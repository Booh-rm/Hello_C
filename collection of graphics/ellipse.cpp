#include <graphics.h>

int main(){
	
	initwindow(800,600, "Ellipse");

	ellipse( 400, 400, 0, 360, 100, 50 );
		
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
