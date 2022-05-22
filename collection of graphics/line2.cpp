#include <graphics.h>

	int main()
{
	initwindow(800,600,"line wiht pixels");
 
	for (int y = 0; y < 400; ++y){
		putpixel(100+y, 200, RGB(127, 45, 45));
	}
    
		
	getch();
 	
	return 0;
}
