/*
Author : Rajob Raihan Monmoy
Email : iammonmoy@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
struct togather{
    int process;
    int brust;
    int priority;
};
bool cmp(togather a , togather b)
{
    if(a.priority < b.priority)
        return 1;
    return 0;
}
int main()
{
    togather input[100];
    int n,time,priority;
    printf("Enter how many process\n");
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        printf("Enter brust time and priority time\n");
        cin>>time>>priority;
        input[i].process=i+1;
        input[i].brust=time;
        input[i].priority=priority;
    }

    sort(input,input+n,cmp);

     int waiting=0;
    double average=0;
    for(int i = 0; i < n; i++)
    {
        average+=waiting;
        printf("process number %d ",input[i].process);
        for(int j = 0; j < input[i].brust; j++)
            printf("#");
        printf(" waiting time %d ",waiting);
        waiting+=input[i].brust;
         printf(" turnaround time %d ",waiting);
         printf("\n");
    }
    printf("average waiting time %lf\n",average/n);
    return 0;
}

