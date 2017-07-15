#include <bits/stdc++.h>
#include<graphics.h>
#include<time.h>
int main()
{
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

   time_t rawTime;
   struct tm *currentTime;
   char a[200];
   while(true){
    rawTime=time(NULL);
    currentTime=localtime(&rawTime);
    strftime(a,100,"%I:%M:%S",currentTime);

    setcolor(1);
    settextstyle(3,HORIZ_DIR,10);
    outtextxy(100,50,a);

    strftime(a,100,"%p",currentTime);
    settextstyle(3,HORIZ_DIR,5);
    outtextxy(300,10,a);

    strftime(a,100,"%a,%d,%b,%Y",currentTime);
    settextstyle(3,HORIZ_DIR,8);
    outtextxy(130,310,a);
    delay(1000);
   }

    getch();
    closegraph();
}
