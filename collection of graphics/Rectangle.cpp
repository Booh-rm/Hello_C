#include <graphics.h>

int main(){
	
	initwindow(800,600, "Rectangle");
	
	rectangle(250, 250, 550, 300);
	
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
