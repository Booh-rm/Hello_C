#include<graphics.h>
 
int main()
{
	int width = 900;
	int height = 600;
	
	initwindow(width,height,"Center Pixel");
 
	putpixel(width/2,height/2,RED);
 	
	getch();
 
	return 0;
}
