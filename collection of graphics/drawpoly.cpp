#include <graphics.h>

int main(){
	
	initwindow(800,600, "drawpoly");
	
	int arr[] = {120, 250, 400, 250, 400,
                 350, 450, 200, 120, 250};
                 
	drawpoly(5, arr);
	
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
