/*
Author : Rajob Raihan Monmoy
Email : iammonmoy@gmail.com
*/
/*
Tutorial :https://www.youtube.com/watch?v=sJOZ3lvJnRI&t=1s
TestCase:
5
100 500 200 300 600
4
212 417 112 426
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int memory,process,mem[1000],pro[1000];
    printf("Enter How Many Partitions\n");
    scanf("%d", &memory);
    for(int i = 0; i < memory; i++)
    {
        printf("Enter Partition Size Of %d\n",i+1);
        scanf("%d", &mem[i]);
    }
    printf("Enter How Many Process\n");
    scanf("%d", &process);
    for(int i = 0; i < process; i++)
    {
        printf("Enter Process Size Of %d\n",i+1);
        scanf("%d", &pro[i]);
    }

    sort(mem,mem+memory);

    bool isoccupied[1000];
    bool isgiven[1000];
    for(int i = 0; i < memory; i++)
    {
         isoccupied[i] = false;
         isgiven[i]=false;
    }

    for(int i = 0; i < process; i++)
    {
        for(int j = memory-1; j >= 0; j--)
        {
            if(!isoccupied[j] && pro[i] <= mem[j])
            {
                isoccupied[j]=true;
                isgiven[i]=true;
                printf("%d KB is GIVEN TO PROCESS %d KB\n",mem[j],pro[i]);
                break;
            }
        }
    }

    for(int i = 0; i < process; i++)
        if(!isgiven[i])
            printf("%d is not allocated in memory\n",pro[i]);
    return 0;
}

