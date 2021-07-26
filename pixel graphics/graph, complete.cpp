#include<graphics.h>
#include <winbgim.h>

/*
-------------------------------------------------------------------------------------------
 @author Booh-rm
-------------------------------------------------------------------------------------------
*/

int main()

{
	initwindow(800,800,"Pixels");
 
 	cleardevice();
 	
 	//-------------------------------------------------------------------
	
	for (int a=1; a<=500; a++){
		putpixel(400,100+a,BLUE);
	}
	for	(int b=1; b<=430; b++){
		putpixel(180+b,350,BLUE);
	}
	
	//-------------------------------------------------------------------

	for (int d=1; d<=31.5; d++){
		putpixel(610-((2/0.30*d)),350-d,RED);
	}
	for (int d=1; d<=31.5; d++){
		putpixel(607-((2/0.30*d)),350-d,RED);
	}
	
	for (int d=1; d<=57; d++){
		putpixel(580-((2/0.64*d)),350-d,RED);
	}
	
	for (int d=1; d<=86; d++){
		putpixel(540-((2/1.24*d)),350-d,RED);
	}
	
	for (int d=1; d<=118; d++){
		putpixel(504-((2/2.30*d)),350-d,RED);
	}
	
	for (int d=1; d<=148; d++){
		putpixel(474-((2/4.10*d)),350-d,RED);
	}
	
	for (int d=1; d<=188; d++){
		putpixel(444-((2/8.80*d)),350-d,RED);
	}
	
	for (int d=1; d<=230; d++){
		putpixel(422-((2/22.80*d)),350-d,RED);
	}
		
	
	//-------------------------------------------------------------------
	
	for (int d=1; d<=31.5; d++){
		putpixel(610-((2/0.30*d)),350+d,RED);
	}for (int d=1; d<=31.5; d++){
		putpixel(607-((2/0.30*d)),350+d,RED);
	}
	
	for (int d=1; d<=57; d++){
		putpixel(580-((2/0.64*d)),350+d,RED);
	}
	
	for (int d=1; d<=86; d++){
		putpixel(540-((2/1.24*d)),350+d,RED);
	}
	
	for (int d=1; d<=118; d++){
		putpixel(504-((2/2.30*d)),350+d,RED);
	}
	
	for (int d=1; d<=148; d++){
		putpixel(474-((2/4.10*d)),350+d,RED);
	}
	
	for (int d=1; d<=188; d++){
		putpixel(444-((2/8.80*d)),350+d,RED);
	}
	
	for (int d=1; d<=230; d++){
		putpixel(422-((2/22.80*d)),350+d,RED);
	}	
	
	//-------------------------------------------------------------------
	
	for (int e=1; e<=32.54; e++){
		putpixel(196+((2/0.31*e)),350-e,RED);
	}
	for (int e=1; e<=32.50; e++){
		putpixel(193+((2/0.30*e)),350-e,RED);
	}
	/*for (int e=1; e<=32.50; e++){
		putpixel(190+((2/0.29*e)),350-e,RED);
	}*/
	
	for (int e=1; e<=55; e++){
		putpixel(226+((2/0.64*e)),350-e,RED);
	}
	
	for (int e=1; e<=86; e++){
		putpixel(256+((2/1.20*e)),350-e,RED);
	}
	
	for (int e=1; e<=120; e++){
		putpixel(292+((2/2.20*e)),350-e,RED);
	}
	
	for (int e=1; e<=149; e++){
		putpixel(328+((2/4.09*e)),350-e,RED);
	}
	
	for (int e=1; e<=189; e++){
		putpixel(356+((2/8.6*e)),350-e,RED);
	}
	
	for (int e=1; e<=230; e++){
		putpixel(380+((2/23.0*e)),350-e,RED);
	}
	
	//-------------------------------------------------------------------
	
	for (int e=1; e<=32.54; e++){
		putpixel(196+((2/0.31*e)),350+e,RED);
	}
	for (int e=1; e<=32.50; e++){
		putpixel(193+((2/0.30*e)),350+e,RED);
	}
	
	for (int e=1; e<=55; e++){
		putpixel(226+((2/0.64*e)),350+e,RED);
	}
	
	for (int e=1; e<=86; e++){
		putpixel(256+((2/1.20*e)),350+e,RED);
	}
	
	for (int e=1; e<=120; e++){
		putpixel(292+((2/2.20*e)),350+e,RED);
	}
	
	for (int e=1; e<=149; e++){
		putpixel(328+((2/4.09*e)),350+e,RED);
	}
	
	for (int e=1; e<=189; e++){
		putpixel(356+((2/8.6*e)),350+e,RED);
	}
	
	for (int e=1; e<=230; e++){
		putpixel(380+((2/23.0*e)),350+e,RED);
	}
	
	//-------------------------------------------------------------------
	
	getch();
 
	return 0;
}
