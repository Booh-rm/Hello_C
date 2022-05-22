#include <graphics.h>

int main(){
	
	initwindow(800,600, "Circle");
	
	circle(400, 300, 100);
	
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
