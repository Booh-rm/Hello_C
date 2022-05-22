#include <graphics.h>

int main(){
	
	initwindow(800,600, "Bar3D");

    int left, top, right, bottom; 
  
    int depth; 

    int topflag; 

    bar3d(left = 220, top = 150, 
    right = 260, bottom = 350, 
    depth = 20, topflag = 1);  
	
	while (!kbhit()){
		delay(1);
	}
	
	return 0;
}
