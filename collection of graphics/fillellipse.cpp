#include <graphics.h>

int main(){
	
	initwindow(800,600, "FillEllipse");

	fillellipse( 400, 200, 100, 50 );
		
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
