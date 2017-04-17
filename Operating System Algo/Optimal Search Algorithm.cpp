/*
Author : Rajob Raihan Monmoy
Email : iammonmoy@gmail.com
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
        /*int pt = 0;
        while(pt < frame)
        {
            pt++;
            int tmp = q.front();
            printf("%d ",tmp);
            q.pop();
            q.push(tmp);
        }
        printf("\n\n");*/

        if(!check[pages[i]])
        {
            int res=-100,mx=-1000,chk=0;
            while(chk < frame)
            {
                chk++;
                int tmp = q.front();
                q.pop();
                q.push(tmp);
                int flag = 0;
                for(int j = i+1; j < page; j++)
                {
                    if(pages[j]==tmp)
                    {
                        if(j > mx)
                        {
                            flag = 1;
                            res = pages[j];
                            mx = j;
                            break;
                        }
                        else break;
                    }
                    else if(j == page-1 && !flag)
                    {
                        res = tmp;
                        mx = 100000;
                    }
                }

            }

            chk = 0;
            while(chk < frame)
            {
                chk++;
                int tmp = q.front();
                q.pop();
                if(tmp == res)
                    continue;
                q.push(tmp);
            }
            check[res]=false;
            check[pages[i]]=true;
            q.push(pages[i]);
            printf("%d is replaced by %d\n",res,pages[i]);
        }

        else
        {
            int chk = 0;
            printf("PAGE HIT %d\n",pages[i]);
        }
    }
    return 0;
}

