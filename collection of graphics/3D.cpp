#include <windows.h>
 
#include <math.h>
 
#define IDT_1 1000
 
RECT re;
bool borrar = true;
const int margenx = 280;
const int margeny = 200;
 
typedef struct tmat
{
  float v[4][4];
};
 
tmat identidad = {
	{{1,0,0,0},
	{0,1,0,0},
	{0,0,1,0},
	{0,0,0,1}}
} ;
tmat mat = identidad;
 
typedef struct tpunto
{
	float x,y,z;
};
 
const int maxp = 8;
 
tpunto lista[maxp] = {
 
 {-50, 50,-50},
 { 50, 50,-50},
 { 50,-50,-50},
 {-50,-50,-50},
 
 {-50, 50, 50},
 { 50, 50, 50},
 { 50,-50, 50},
 {-50,-50, 50},
 
};
 
typedef struct tvertice2D
{
	int x, y;
};
tvertice2D vert2D[maxp];
 
void aplicar_mat(tpunto a,tpunto *b)
{
	b->x=mat.v[0][0]*a.x+mat.v[0][1]*a.y+mat.v[0][2]*a.z+mat.v[0][3]*1;
	b->y=mat.v[1][0]*a.x+mat.v[1][1]*a.y+mat.v[1][2]*a.z+mat.v[1][3]*1;
	b->z=mat.v[2][0]*a.x+mat.v[2][1]*a.y+mat.v[2][2]*a.z+mat.v[2][3]*1;
}
 
void dibujar(HDC hdc)
{
	int i;
	float x,y;
	tpunto dato;
	int getmaxx=150;
	int getmaxy=150;
	HPEN hPen;
	if(borrar == true) hPen = CreatePen(PS_SOLID,1,RGB(255,255,255));
	else  hPen = CreatePen(PS_SOLID,1,RGB(0,0,0));
	SelectObject(hdc, hPen);
 
	for(i = 0; i < maxp; i++)
	{
 
		aplicar_mat(lista[i], &dato);
 
		x = dato.x * 1000 / (1000 + dato.z); 
		y = dato.y * 1000 / (1000 + dato.z);
 
		vert2D[i].x = margenx + x; 
		vert2D[i].y = margeny + y;
	}
 
	//Unir primer vértice (0) con el segundo (1)	
	MoveToEx(hdc, vert2D[0].x, vert2D[0].y, NULL);
	LineTo(hdc, vert2D[1].x, vert2D[1].y);
	//Unir segundo vértice (1) con el tercero (2)	
	LineTo(hdc, vert2D[2].x, vert2D[2].y);
	//Unir tercer vértice (2) con el cuarto (3)	
	LineTo(hdc, vert2D[3].x, vert2D[3].y);
	//Unir cuarto vértice (3) con el primero (1)
	LineTo(hdc, vert2D[0].x, vert2D[0].y);
 
	//Unir quinto vértice (4) con el sexto (5)	
	MoveToEx(hdc, vert2D[4].x, vert2D[4].y, NULL);
	LineTo(hdc, vert2D[5].x, vert2D[5].y);
	//Unir sexto vértice (5) con el séptimo (6)	
	LineTo(hdc, vert2D[6].x, vert2D[6].y);
	//Unir séptimo vértice (6) con el octavo (7)	
	LineTo(hdc, vert2D[7].x, vert2D[7].y);
	//Unir octavo vértice (7) con el quinto (4)
	LineTo(hdc, vert2D[4].x, vert2D[4].y);
 
	//Unir primer vértice (0) con el quinto (4) 
	MoveToEx(hdc, vert2D[0].x, vert2D[0].y, NULL);
	LineTo(hdc, vert2D[4].x, vert2D[4].y);
	//Unir segundo vértice (1) con el sexto (5)
	MoveToEx(hdc, vert2D[1].x, vert2D[1].y, NULL);
	LineTo(hdc, vert2D[5].x, vert2D[5].y);
	//Unir tercer vértice (2) con el séptimo (6)
	MoveToEx(hdc, vert2D[2].x, vert2D[2].y, NULL);
	LineTo(hdc, vert2D[6].x, vert2D[6].y);
	//Unir cuarto vértice (3) con el octavo (7)
	MoveToEx(hdc, vert2D[3].x, vert2D[3].y, NULL);
	LineTo(hdc, vert2D[7].x, vert2D[7].y);
 
	DeleteObject(hPen);
	if(borrar==true) borrar=false;
	else borrar = true;
}
 
void multiplica(tmat a, tmat b, tmat *c)
{
	int i,j,k;
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	{
		c->v[i][j]=0;
		for(k=0;k<4;k++) c->v[i][j]+=a.v[i][k]*b.v[k][j];
 
	}
}
 
void rotarx(float ang)
{
	tmat rot,aux;
	float dcos=cos(ang*3.1416/180);
	float dsin=sin(ang*3.1416/180);
	rot=identidad;
	rot.v[1][1]=dcos;
	rot.v[1][2]=-dsin;
	rot.v[2][1]=dsin;
	rot.v[2][2]=dcos;
	aux=mat;
	multiplica(rot,aux,&mat);
}
 
void rotary(float ang)
{
	tmat rot,aux;
	float dcos=cos(ang*3.1416/180);
	float dsin=sin(ang*3.1416/180);
	rot=identidad;
	rot.v[0][0]=dcos;
	rot.v[0][2]=dsin;
	rot.v[2][0]=-dsin;
	rot.v[2][2]=dcos;
	aux=mat;
	multiplica(rot,aux,&mat);
}
 
void rotarz(float ang)
{
	tmat rot,aux;
	float dcos=cos(ang*3.1416/180);
	float dsin=sin(ang*3.1416/180);
	rot=identidad;
	rot.v[0][0]=dcos;
	rot.v[0][1]=-dsin;
	rot.v[1][0]=dsin;
	rot.v[1][1]=dcos;
	aux=mat;
	multiplica(rot,aux,&mat);
}
 
/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch(Message)
	{
		case WM_CREATE:
		{
			SetTimer( hwnd, IDT_1, 25, NULL );
			break;
		}
		case WM_SIZE:{
			GetClientRect(hwnd, &re);
			break;
		}
		case WM_TIMER:{
			switch(wParam){
      			case IDT_1:{
 
      				hdc = GetDC(hwnd);
 
      				dibujar(hdc);
 
					rotary(3);
      				rotarx(3);
      				rotarz(3);
 
					dibujar(hdc);
 
					ReleaseDC(hwnd, hdc);
 
      				break;
				}
      		}
      		break;
		}
		case WM_DESTROY: {
			PostQuitMessage(0);
			KillTimer(hwnd, IDT_1);
			break;
		}
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}
 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */
 
	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
 
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */
 
	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
 
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Cubo 3D",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		600,
		500,
		NULL,NULL,hInstance,NULL);
 
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
 
	while(GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
