#include<stdio.h>
#include<math.h>

void linebres(int xa, int ya, int xb, int yb)
{
	int dx = abs(xa-xb), dy = abs(ya-yb);
	int p= 2*dy-dx;
	int twody = 2*dy, twodydx = 2*(dy-dx);
	int x,y,xEnd;

	if(xa>xb)
	{
		x=xb;
		y=yb;
		xEnd = xa;
	}

	else{
		x=xa;
		y=ya;
		xEnd =xb;
	}

	setpixel (x,y);
	while(x<xEnd){
		x++;
		if(p<0)
			p+=twody;
		else{
			y++;
			p+=twodydx;
		}
		setpixel(x,y);
	}
}
