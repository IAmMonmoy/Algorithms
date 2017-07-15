#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const int x_max = 450;
const int y_max = 350;
const int x_min = 150;
const int y_min = 100;

void drawwindow()
{
    line(150,100,450,100);
    line(450,100,450,350);
    line(450,350,150,350);
    line(150,350,150,100);
}

int computeCode(double x, double y)
{
    int code = INSIDE;

    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if (y < y_min)
        code |= BOTTOM;
    else if (y > y_max)
        code |= TOP;

    return code;
}

void cohenSutherlandClip(double x1, double y1,
                         double x2, double y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            double x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout<<"Line Accepted"<<endl;
        drawwindow();
        line(x1,y1,x2,y2);
        delay(5000);
    }
    else
    {
        cout << "Line rejected" << endl;
        drawwindow();
        delay(5000);
    }

}

// Driver code
int main()
{
    int gd=DETECT,v,gm,x1,y1,x2,y2;

    std::cout<<"\nEnter x1 and y1\n";
    std::cin>>x1>>y1;
    std::cout<<"\nEnter x2 and y2\n";
    std::cin>>x2>>y2;

    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    drawwindow();
    delay(500);

    cout<<"before Clipping"<<endl;
    line(x1,y1,x2,y2);
    delay(5000);

    cleardevice();
    cohenSutherlandClip(x1, y1, x2, y2);

    return 0;
}
