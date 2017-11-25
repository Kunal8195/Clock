#include<graphics.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
void main()
{

  // coordinates info for hour
  int coordsforhourX[12]={50,87,100,87,50,0,-50,-87,-100,-87,-50,0};
  int coordsforhourY[12]={-87,-50,0,50,87,100,87,50,0,-50,-87,-100};
  int coordForMinSecX[60]={0,18,35,53,69,85,100,114,126,138,147,155,162,166,169,170,169,166,162,155,147,138,126,114,100,85,69,53,35,18,0,-18,-35,-53,-69,-85,-100,-114,-126,-138,-147,-155,-162,-166,-169,-170,-169,-166,-162,-155,-147,-138,-126,-114,-100,-85,-69,-53,-35,-18};
  int coordForMinSecY[60]={-170,-169,-166,-162,-155,-147,-138,-126,-144,-100,-85,-69,-53,-35,-18,0,18,35,53,69,85,100,114,126,138,147,155,162,166,169,170,169,166,162,155,147,138,126,114,100,85,69,53,35,18,0,-18,-35,-53,-69,-85,-100,-114,-126,-138,-147,-155,-162,-166,-169};

  //time related Variable
  time_t rawTime;
  struct tm * currentTime;
  char a[100];

  //to get midpoint of graph

  int midX=320;//getmaxx()/2;
  int midY=233;  //getmaxy()/2;

  //variables for storing hour, minutes, and Second info.

  int IMS;

  /////////////////////////////////////////
  int gd=DETECT;
  int gm;
  initgraph(&gd, & gm, "c:\\TURBOC3\\BGI");
  //////////////////////////////////////////////////

  // Time related functions
 //  while(1)
  {

  rawTime = time(NULL);
  currentTime= localtime(&rawTime);
  /////DIGITAL CLOCK PART/////
  strftime(a,40,"%I:%M:%S", currentTime);
  setcolor(11);
  settextstyle(3,HORIZ_DIR,2);
  outtextxy(265,273,a);

  strftime(a,40,"%p",currentTime);
  settextstyle(3,HORIZ_DIR,2);
  outtextxy(365, 273,a);

  strftime(a,40,"%a %d%b %Y",currentTime);
  settextstyle(3,HORIZ_DIR,2);
  outtextxy(250,300,a);

  // Drawing the circle

  setcolor(WHITE);
  circle(midX, midY,200);
  outtextxy(284,245,"Kunal Pal");

  outtextxy(midX +102, midY-165, "1");
  outtextxy(midX +159, midY-110, "2");
  outtextxy(midX +183, midY-15, "3");
  outtextxy(midX +160, midY+80, "4");
  outtextxy(midX +95, midY+145, "5");
  outtextxy(midX +0, midY+173, "6");
  outtextxy(midX -100, midY+145, "7");
  outtextxy(midX -170, midY+75, "8");
  outtextxy(midX -190, midY-15, "9");
  outtextxy(midX -176, midY-105, "10");
  outtextxy(midX -110, midY-170, "11");
  outtextxy(midX -10, midY-200, "12");

  // Getting the time info & converting it to integer
  // setting the color & drawing the line

  strftime(a,100, "%I",currentTime);
  sscanf(a, "%d",&IMS);
  setcolor(RED);
  line(midX,midY,midX+coordsforhourX[IMS-1],midY+coordsforhourY[IMS-1]);

  strftime(a,100,"%M",currentTime);
  sscanf(a,"%d", &IMS);
  setcolor(YELLOW);
  line(midX,midY,midX+coordForMinSecX[IMS],midY+coordForMinSecY[IMS]);

  strftime(a,100,"%S",currentTime);
  sscanf(a,"%d",&IMS);
  setcolor(GREEN);
  line(midX,midY,midX+coordForMinSecX[IMS],midY+coordForMinSecY[IMS]);
 // delay(1000);
 // cleardevice();
  }

  getch();
  closegraph();
}
