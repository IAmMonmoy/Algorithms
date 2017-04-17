/*
Author : Rajob Raihan Monmoy
Email : iammonmoy@gmail.com
*/
#include <bits/stdc++.h>`
using namespace std;
struct togather{
    int process;
    int brust;
};
bool cmp(togather a , togather b)
{
    if(a.brust < b.brust)
        return 1; // SAME
    return 0;//WILL SWAP
}
int main()
{
    togather input[100];
    int n,time;
    printf("Enter how many process\n");
    cin>>n;
    printf("Enter brust time for each process\n");
    for(int i = 0; i < n; i++)
    {
        cin>>time;
        input[i].process=i+1;
        input[i].brust=time;
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
