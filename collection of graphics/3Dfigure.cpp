#include <graphics.h>

int main(){
	
	initwindow(800,600, "Figure 3D");
	
	rectangle(300, 100, 500, 300);
	
	rectangle(250, 150, 450, 350);
	
	line(300, 100, 250, 150);

	line(500, 100, 450, 150);
		
	line(500, 300, 450, 350);
	
	line(300, 300, 250, 350);
	
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
