/*
Author : Rajob Raihan Monmoy
Email : iammonmoy@gmail.com
*/
#include <bits/stdc++.h>

using namespace std;
struct togather{
    int process;
    int brust;
    int brust_var;
};
int main()
{
    togather input[100];
    int n,time,quantum;
    printf("Enter how many process\n");
    cin>>n;
    printf("Enter Time quantum\n");
    cin>>quantum;
    printf("Enter brust time for each process\n");
    for(int i = 0; i < n; i++)
    {
        cin>>time;
        input[i].process=i+1;
        input[i].brust=time;
        input[i].brust_var=time;
    }

    queue<togather>ab;

    for(int i = 0; i < n; i++)
        ab.push(input[i]);


    int waiting=0;
    double average=0;
    while(!ab.empty())
    {
        togather pt = ab.front();
        ab.pop();
        if(pt.brust_var-quantum > 0)
        {
            pt.brust_var-=quantum;
            ab.push(pt);
            waiting+=quantum;
            printf("Process name %d\n",pt.process);
        }
        else
        {
            waiting+=pt.brust_var;
            average+=(waiting-pt.brust);
            printf("Process name %d , waiting time %d , turnaround time %d\n",pt.process,waiting-pt.brust,waiting);
        }
    }

    printf("Average waiting time %lf\n",average/n);
    return 0;
}

