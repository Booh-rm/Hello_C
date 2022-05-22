#include<graphics.h>
#include<conio.h>
#include<dos.h>

main()
{
   int gd = DETECT, gm, x, y, color, angle = 0;
   struct arccoordstype a, b;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   delay(1000);                                                                
   while(angle<=360)
   {
   	
   	//----------------------------------------------------
      
      setcolor(GREEN);
      circle(318,240,25);
      
      setcolor(BLUE);
      line(318,265,318,415);
      
      setcolor(BLUE);
      line(318,215,318,65);
      
      setcolor(BLUE);
      line(292,240,145,240);
      
      setcolor(BLUE);
      line(342,240,489,240);
      
      setcolor(YELLOW);
      circle(318,240,174);
      
      //----------------------------------------------------
      
   	  setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,50);
      setcolor(BLUE);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
   	
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,100);
      setcolor(RED);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,150);
      getarccoords(&a);
      setcolor(GREEN);
      circle(a.xstart,a.ystart,25);
      
      //----------------------------------------------------
      
      angle = angle+5;
      delay(50);
      
      //----------------------------------------------------
   }
   getch();
   closegraph();
}
