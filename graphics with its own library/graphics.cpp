#include <graphics.h>
#include <graphicsLibrary.h>
#include <conio.h>

 main(){
	
	initwindow(1400,800, "Graficas");

	graphicsLibrary g;

	//----------------------------------------------------

	g.pixel(100, 900, RED);
	
	g.rectangle(150,400,400,370);
	
	g.square(460,650,200);
	
	g.trectangle(150,260,100,200);
	
	g.tequilatero(460, 300, 200);
	
	g.estilo(0,14);	
	g.pentagon(200,650,100);
	
	//g.poligon({5,5,5,5,5},5);
	
	g.circle(1200,150,90);

	g.cube(800,300,150);
	
	g.cubep(800,650,150,200);
	//----------------------------------------------------
			
	while (!kbhit()){
		delay(1);
	}

	return 0;
}
