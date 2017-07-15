#include<bits/stdc++.h>
#include<graphics.h>
int main()
{
    int driver=DETECT,mode=0;
    initgraph(&driver,&mode,"c:\\tc\\bgi");

    setcolor(WHITE);
    circle(292,240,100);
    setfillstyle(SOLID_FILL,RED);
    floodfill(292,240,WHITE);

    setcolor(WHITE);
    rectangle(40,80,600,400);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(90,120,WHITE);

    setcolor(WHITE);
    line(38,80,38,479);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(38,240,WHITE);

    getch();
    closegraph();

}
