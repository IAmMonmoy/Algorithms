/*
Author : Rajob Raihan Monmoy
Email : iammonmoy@gmail.com
*/
/*
TestCase :
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int page,pages[1000],frame;
    printf("Enter How Many pages\n");
    scanf("%d", &page);
    printf("Enter All The Pages\n");
    for(int i = 0; i < page; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter How Many frames\n");
    scanf("%d", &frame);

    queue<int>q;
    bool check[1000];

    for(int i = 0; i < 1000; i++)
        check[i]=false;

    for(int i = 0; i<page && q.size() < frame; i++)
    {
        if(!check[pages[i]])
        {
            q.push(pages[i]);
            check[pages[i]]=true;
            printf("%d Entered In The Frame\n",pages[i]);
        }
        else
        {
            printf("PAGE HIT FOR %d\n",pages[i]);
        }
    }

    for(int i = frame; i < page; i++)
    {
        int pt = 0;
        while(pt < frame)
        {
            pt++;
            int tmp = q.front();
            printf("%d ",tmp);
            q.pop();
            q.push(tmp);
        }
        printf("\n\n");

        if(!check[pages[i]])
        {
            int tmp = q.front();
            q.pop();
            check[tmp]=false;
            q.push(pages[i]);
            check[pages[i]]=true;
            printf("%d is replaced by %d\n",tmp,pages[i]);
        }
        else {
            printf("PAGE HIT FOR %d\n",pages[i]);
        }
    }
}
