#include <graphics.h>

int main(){
	
	initwindow(800,600, "Square");
	
	rectangle(300, 200, 500, 400);
	
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
