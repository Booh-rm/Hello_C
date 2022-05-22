#include <graphics.h>

int main(){
	
	initwindow(800,600, "Irregular polygon");

	line(200, 280, 300, 320);
	
	line(300, 320, 400, 330);
	
	line(400, 330, 450, 240);
    
    line(450, 240, 560, 210);
    
    line(560, 210, 430, 160);
    
    line(430, 160, 340, 215);
    
    line(340, 215, 270, 170);
    
    line(270, 170, 200, 280);
		
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
