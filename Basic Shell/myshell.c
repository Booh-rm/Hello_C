#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>

/*----------------------------------------------------------------------------------------------------------*/

/**Booh*/

/*----------------------------------------------------------------------------------------------------------*/

#define MAX_LENGTH 100
#define MAX_ARGS 10

/*----------------------------------------------------------------------------------------------------------*/

void clr()
{
    system("clear");
}

/*----------------------------------------------------------------------------------------------------------*/

void dir(char *directory)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(directory)) != NULL)
    {

        while ((ent = readdir(dir)) != NULL)
        {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    }
    else
    {
        perror("");
    }
}

/*----------------------------------------------------------------------------------------------------------*/

void imprimir_entorno()
{
    extern char **environ;
    int i = 0;
    for (i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}

/*----------------------------------------------------------------------------------------------------------*/

void echo(char *args[])
{
    int i;
    for (i = 1; args[i] != NULL; i++)
        printf("%s ", args[i]);
    printf("\n");
}

/*----------------------------------------------------------------------------------------------------------*/

void cd(char *args[])
{
    if (args[1] == NULL)
        printf("Falta argumento\n");
    else
    {
        if (strcmp(args[1], "..") == 0)
        {
            if (chdir("..") != 0)
                printf("Error al cambiar de directorio\n");
            else
            {
                char cwd[1024];
                if (getcwd(cwd, sizeof(cwd)) != NULL)
                    setenv("PWD", cwd, 1);
            }
        }
        else
        {
            if (chdir(args[1]) != 0)
                printf("Error al cambiar de directorio\n");
            else
            {
                char cwd[1024];
                if (getcwd(cwd, sizeof(cwd)) != NULL)
                    setenv("PWD", cwd, 1);
            }
        }
    }
}

/*----------------------------------------------------------------------------------------------------------*/

void help()
{
    printf("\n1. cd <directorio> -> cambia el directorio actual a <directorio>.\n");
    printf("Si el argumento <directorio> no aparece, devuelve el directorio actual.\n");
    printf("\n2. clr -> limpia la pantalla.\n");
    printf("\n3. dir <directorio> -> lista el contenido de <directorio>.\n");
    printf("\n4. environ -> muestra todas las variables de entorno.\n");
    printf("\n5. echo <comentario> -> muestra <comentario> en la pantalla.\n");
    printf("\n6. help -> muestra el manual de usuario.\n");
    printf("\n7. pausa -> detiene la ejecución del interprete de mandatos hasta que se pulse ‘Enter’.\n");
    printf("\n8. quit -> sale del interprete de mandatos.\n");
    printf("\n");
}

/*----------------------------------------------------------------------------------------------------------*/

void pausa()
{
    printf("Presiona Enter para continuar...");
    getchar();
}

/*----------------------------------------------------------------------------------------------------------*/

void pwd()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s\n", cwd);
    else
        perror("getcwd() error");
}

/*----------------------------------------------------------------------------------------------------------*/

void quit()
{
    exit(0);
}

//----------------------------------------------------------------

void redirect_input(char *input_file)
{
    int fd = open(input_file, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return;
    }
    if (dup2(fd, STDIN_FILENO) == -1)
    {
        perror("dup2");
        return;
    }
    close(fd);
}

void redirect_output(char *output_file, int append)
{
    int flags = O_WRONLY | O_CREAT;
    if (!append)
        flags |= O_TRUNC;
    else
        flags |= O_APPEND;

    int fd = open(output_file, flags, 0644);
    if (fd == -1)
    {
        perror("open");
        return;
    }

    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        return;
    }

    close(fd);
}

void run_dir(char *input_file, char *output_file, int append)
{
    if (input_file != NULL)
    {
        redirect_input(input_file);
    }
    if (output_file != NULL)
    {
        redirect_output(output_file, append);
    }
    execlp("dir", "dir", NULL);
}

void run_imprimir_entorno(char *input_file, char *output_file, int append)
{
    if (input_file != NULL)
    {
        redirect_input(input_file);
    }
    if (output_file != NULL)
    {
        redirect_output(output_file, append);
    }
    execlp("imprimir_entorno", "imprimir_entorno", NULL);
}

void run_echo(char *input_file, char *output_file, int append, int argc, char *argv[])
{
    FILE *fp;
    char command[MAX_LENGTH];
    int i;

    if (input_file != NULL)
    {
        strcpy(command, "cat ");
        strcat(command, input_file);

        fp = popen(command, "r");

        while (fgets(command, MAX_LENGTH, fp))
        {
            printf("%s", command);
        }
        pclose(fp);
    }

    else if (output_file != NULL)
    {
        strcpy(command, "echo");
        for (i = 1; i < argc; i++)
        {
            strcat(command, " ");
            strcat(command, argv[i]);
        }
        if (append)
            strcat(command, " >>");
        else
            strcat(command, " >");
        strcat(command, " ");
        strcat(command, output_file);
        fp = popen(command, "w");
        pclose(fp);
    }
    else
    {
        for (i = 1; i < argc; i++)
        {
            printf("%s ", argv[i]);
        }
        printf("\n");
    }
}

void run_help(char *input_file, char *output_file, int append)
{
    if (input_file != NULL)
    {
        redirect_input(input_file);
    }
    if (output_file != NULL)
    {
        redirect_output(output_file, append);
    }
    execlp("help", "help", NULL);
}

//----------------------------------------------------------------

/*----------------------------------------------------------------------------------------------------------*/

int main(int argc, char *argv[])
{

    printf("         '''\n");
    printf("                       '\n");
    printf("            .         '   '   @Booh!\n");
    printf("          .         '       '        .    .     .  .  .\n");
    printf("        .      .  '  .        '              .         '\n");
    printf("      .    '             '      '   .  .  .          '   '\n");
    printf("████  . ████ ██    ██   ███████ ██    ██ ███████ ██      ██\n");
    printf("██  ████  ██ ██    ██   ██      ██    ██ ██      ██      ██\n");
    printf("██   .    ██ ████████   ███████ ████████ ███████ ██      ██\n");
    printf("██    .   ██    ██           ██ ██    ██ ██      ██      ██\n");
    printf("██     .  ██    ██      ███████ ██    ██ ███████ ███████ ███████\n");
    printf("    .    '   '....'    .           ...'.      ' .\n");
    printf("       '  .            .         .     '          '     '  v0.1\n");
    printf("             '  .  .  .  .  . '.    .'      .       '  .\n");
    printf("                 '         '    '. '      .   Intended for use in linux\n");
    printf("                   '       '      '     .\n");
    printf("                     ' .  '           .\n");
    printf("                         '''\n");
    printf("\n");
    char input[MAX_LENGTH];
    char *args[MAX_LENGTH];
    int count;
    int background = 0;

    while (1)
    {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            printf("%s/myshell> ", cwd);
        else
            perror("Error al obtener directorio actual");

        fgets(input, MAX_LENGTH, stdin);

        count = 0;
        args[count] = strtok(input, " \n");

        while (args[count] != NULL)
        {
            count++;
            args[count] = strtok(NULL, " \n");
        }
        if (strcmp(args[count - 1], "&") == 0)
        {
            background = 1;
            args[count - 1] = NULL;
        }
        else
        {
            background = 0;
        }

        //----------------------------------------------------------------
        char *input_file = NULL, *output_file = NULL;
        int append = 0;

        for (int i = 1; i < count; i++)
        {
            if (strcmp(args[i], "<") == 0)
            {
                input_file = args[++i];
            }
            else if (strcmp(args[i], ">") == 0)
            {
                output_file = args[++i];
            }
            else if (strcmp(args[i], ">>") == 0)
            {
                output_file = args[++i];
                append = 1;
            }
        }
        //----------------------------------------------------------------

        if (strcmp(args[0], "cd") == 0)
            cd(args);
        else if (strcmp(args[0], "clr") == 0)
            clr();
        else if (strcmp(args[0], "dir") == 0)
        {
            if (input_file != NULL || output_file != NULL)
            {
                run_dir(input_file, output_file, append);
            }
            else
            {
                if (count > 1)
                    dir(args[1]);
                else
                    dir(".");
            }
        }
        else if (strcmp(args[0], "environ") == 0)
        {
            if (input_file != NULL || output_file != NULL)
            {
                run_imprimir_entorno(input_file, output_file, append);
            }
            else
            {
                imprimir_entorno();
            }
        }
        else if (strcmp(args[0], "echo") == 0)
        {
            if (input_file != NULL || output_file != NULL)
            {
                run_echo(input_file, output_file, append, count, args);
            }
            else
            {
                int i;
                for (i = 1; i < count; i++)
                {
                    printf("%s ", args[i]);
                }
                printf("\n");
            }
        }
        else if (strcmp(args[0], "help") == 0)
            help();
        else if (strcmp(args[0], "pause") == 0)
            pausa();
        else if (strcmp(args[0], "pwd") == 0)
            pwd();
        else if (strcmp(args[0], "quit") == 0)
            quit();
        else
        {
            pid_t pid = fork();
            if (pid == 0)
            {
                execvp(args[0], args);
                printf("Comando desconocido\n");
                exit(1);
            }
            else if (pid > 0)
            {
                if (!background)
                    wait(NULL);
            }
            else
            {
                perror("fork() error");
            }
        }
    }

    return 0;
}

/*----------------------------------------------------------------------------------------------------------*/