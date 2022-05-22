#include <graphics.h>

int main(){
	
	initwindow(800,600, "line");
	
	line(100, 200, 500, 150);
	
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
