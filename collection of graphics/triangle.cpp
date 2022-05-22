#include <graphics.h>

int main(){
	
	initwindow(800,600, "Triangle");

	line(200, 300, 500, 300);
	
	line(200, 300, 350, 150);
	
	line(500, 300, 350, 150);
    
		
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
