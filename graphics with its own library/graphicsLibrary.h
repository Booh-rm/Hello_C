#ifndef GRAPHICSLIBRARY:H
#define GRAPHICSLIBRARY:H
#include <winbgim.h>
#include <graphics.h>
#include <windows.h>
#include <limits.h>
#include <sstream>
#include <iostream>
#include <math.h>

class graphicsLibrary
	{
		
	//---------------------------------------------------
		
		public:
			void pixel(int x, int y, int color)
			{
				putpixel(x,y,color);
			}
		
	//---------------------------------------------------
		
		void linePixel(int x1, int y1, int x2, int y2)
		{
			
			int i,y;
					
			if (x1>x2){ 
				double m = double(y2-y1)/double(x2-x1);
				for (i=x2; i<=x1; i++)
				{	
					y=m*(i-x1) + y1;
						
					pixel(i,y,2);
				}
			}
				
			else{
				int i,y;
						
				if(x2>x1){
					double m = double(y2-y1)/double(x2-x1);
					for (i=x1; i<=x2; i++)
					{
						y=m*(i-x1) + y1;
						pixel(i,y,2);
					}	
				}
					
				else{
					int i,y;		
						
					if(y1>y2 & x1-x2==0 ){
							
						for (i=y2; i<=y1; i++)
						{
							pixel(x1,i,2);
						}	
					}
						
					else{
						int i,y;		
						
						if(y2>y1 & x1-x2==0 ){

							for (i=y1; i<=y2; i++)
							{
								pixel(x1,i,2);
							}	
						}
							
						else{
							int i,y;
										
							if(y2-y1==0 & x1-x2==0 ){
									
								pixel(x1,y1,2);	
							}	
						}	
					}	
				}
			}		
		}
	
	//---------------------------------------------------
	
		void rectangle(int x1, int y1, int x2, int y2)
		{
			linePixel(x1,y1,x1,y2);
			linePixel(x1,y2,x2,y2);
			linePixel(x1,y1,x2,y1);
			linePixel(x2,y1,x2,y2);
		}
			
	//---------------------------------------------------
			
		void square (int x1, int y1, int L)
		{
			linePixel(x1,y1,x1,(y1-L));
			linePixel(x1,y1,(x1+L),y1);
			linePixel((x1+L),(y1-L),x1,(y1-L));
			linePixel((x1+L),y1,(x1+L),(y1-L));
		}
		
		
	//---------------------------------------------------
			
		void trectangle(int x1,int y1,int L1, int L2)
		{
			linePixel(x1,y1,x1,(y1-L1));
			linePixel(x1,y1,(x1+L2),y1);
			linePixel(x1,(y1-L1),(x1+L2),y1);
		}
			
		//---------------------------------------------------
			
		void tequilatero(int x1, int y1, int L)
		{
			linePixel(x1,y1,(x1+L),y1);
			linePixel((x1+L),y1,(x1+(L/2)),(y1-L));
			linePixel((x1+(L/2)),(y1-L),x1,y1);
		}
			
		//---------------------------------------------------
		
		void pentagon(int x1, int y1, int L)
		{
			linePixel(x1,y1,(x1+L),y1);
			linePixel(x1,y1,(x1-(L/4)),(y1-L));
			linePixel((x1+L),y1,(x1+L)+(L/4),(y1-L));
			linePixel((x1-(L/4)),(y1-L),(x1+(L/2)),(y1-L)-(L/1.7));
			linePixel((x1+L)+(L/4),(y1-L),(x1+(L/2)),(y1-L)-(L/1.7));
		}		
		
		//---------------------------------------------------
		
		void poligon(int Points[], int Sides)
		{
			int limit = (sizeof(Points)/sizeof(Points[0]));
			for (int i = 0; i < limit; i++)
    		{
            	
    		}
		}
		
		//---------------------------------------------------
		
		void circle(int x, int y, int r)
		{
			static const double PI = 3.1415926535;

		    double i, angle, x1, y1;
	
	        for(i = 0; i < 360; i += 0.1)
	        {
	            angle = i;
	            x1 = r * cos(angle * PI / 180);
	            y1 = r * sin(angle * PI / 180);
	            
				pixel(x + x1, y + y1, 2);
	        } 
		}
		
		//---------------------------------------------------
		
		void cube(int x, int y, int l)
		{	
			square(x,y,l);
			square(x+(l/2),y-(l/2),l);
			
			linePixel(x,y-l,(x+(l/2)),((y-(l/2))-l));
			linePixel(x+l,y-l,(x+(l/2)+l),((y-(l/2))-l));
			linePixel(x,y,(x+(l/2)),((y-(l/2))));
			linePixel(x+l,y,(x+(l/2)+l),((y-(l/2))));
		}

		//---------------------------------------------------
		
		void cubep(int x, int y, int l, int p)
		{	
			square(x,y,l);
			square(x+(p),y-(l/2),l);
			
			linePixel(x,y-l,(x+p),((y-(l/2))-l));
			linePixel(x+l,y-l,((x+p)+l),((y-(l/2))-l));
			linePixel(x,y,(x+p),((y-(l/2))));	
			linePixel(x+l,y,((x+p)+l),((y-(l/2))));
		}
		
				
		//---------------------------------------------------
		
		//---------------------------------------------------
		//	  			   P A R E N T S
		//---------------------------------------------------
		
			void style(int parent, int colorF)			
			{
				if(colorF==0)
				{
					setcolor(0);
				}
				else if(colorF==1)
				{
					setcolor(1);
				}
				else if(colorF==2)
				{
					setcolor(2);
				}
				else if(colorF==3)
				{
					setcolor(3);
				}
				else if(colorF==4)
				{
					setcolor(4);
				}
				else if(colorF==5)
				{
					setcolor(5);
				}
				else if(colorF==6)
				{
					setcolor(6);
				}
				else if(colorF==7)
				{
					setcolor(7);
				}
				else if(colorF==8)
				{
					setcolor(8);
				}
				else if(colorF==9)
				{
					setcolor(9);
				}
				else if(colorF==10)
				{
					setcolor(10);
				}
				else if(colorF==11)
				{
					setcolor(11);
				}
				else if(colorF==12)
				{
					setcolor(12);
				}
				else if(colorF==13)
				{
					setcolor(13);
				}
				else if(colorF==14)
				{
					setcolor(14);
				}
				else if(colorF==15)
				{
					setcolor(15);
				}
				
				if(parent==0)
				{
					
				}
				
				else if(parent==1)
				{
					
				}
			}
		
	};
#endif
