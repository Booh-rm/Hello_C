#include <graphics.h>
#include <conio.h>

int main(){
	
	initwindow(800,600, "Bar3D");
	
	int color, backfill;
	
	color = 11;
    backfill = 11;

    setfillstyle( backfill, color );
	bar3d( 250, 220, 450, 320, 25, 1 );
	
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
