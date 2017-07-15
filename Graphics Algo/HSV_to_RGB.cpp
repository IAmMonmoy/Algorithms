#include<bits/stdc++.h>
using namespace std;
float r,g,b;

void hsvToRgb(float h,float s,float v)
{
    int i;
    float aa,bb,cc,f;

     if(s==0)
     {
         r=g=b=v;
     }
     else
     {
         if(h==1.0)
         {
             h=0;
         }

         h = h*6.0;
         i = floor(h);
         f = h-i;

         aa = v*(1-s);
         bb = v*(1-(s*f));
         cc = v*(1-(s*(1-f)));

         switch (i)
         {
             case 0: r = v;  g = cc; b = aa; break;
             case 1: r = bb; g = v;  b = aa; break;
             case 2: r = aa; g = v;  b = cc; break;
             case 3: r = aa; g = bb; b = v;  break;
             case 4: r = cc; g = aa; b = v;  break;
             case 5: r = v;  g = aa; b = bb; break;
         }
     }
}

int main()
{
    float h,s,v;
    cout<<"Enter the Values(H S V):"<<endl;
    cin>>h>>s>>v;

    hsvToRgb(h,s,v);

    cout<<"R = "<<r<<endl;
    cout<<"G = "<<g<<endl;
    cout<<"B = "<<b<<endl;


    return 0;
}
