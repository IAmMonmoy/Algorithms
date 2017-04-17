/*
Author : Rajob Raihan Monmoy
Email : iammonmoy@gmail.com
*/
/*
Tutorial : https://www.youtube.com/watch?v=F1CamLlyIOA
TestCase:
3
5
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2
*/
#include <bits/stdc++.h>
using namespace std;
int allocation[1000][1000],mx[1000][1000],avilable[1000],need[1000][1000];
int main()
{
    int resource,process;
    printf("Enter How Many Resources\n");
    cin>>resource;
    printf("Enter How Many Process\n");
    cin>>process;
    printf("Enter Allocation\n");
    for(int i = 0; i < process; i++)
        for(int j = 0; j < resource; j++)
            cin>>allocation[i][j];

    printf("Enter MAX resources\n");
    for(int i = 0; i < process; i++)
        for(int j = 0; j < resource; j++)
            cin>>mx[i][j];

    printf("Enter Avilable resources\n");
    for(int i = 0; i < resource; i++)
            cin>>avilable[i];

    for(int i = 0; i < process; i++)
        for(int j = 0; j < resource; j++)
            need[i][j] = mx[i][j]-allocation[i][j];

    int changed=0,total=0;
    vector<int>result;
    bool visited[1000];
    memset(visited,false,sizeof(visited));

    for(int i = 0; total != process; i++)
    {
        if(visited[i])
            continue;

        if(i == process)
        {
            if(total > changed)
            {
                changed=total;
                i=0;
            }
            else
                break;
        }

        int flag=0;
        for(int j = 0; j < resource; j++)
        {
            if(need[i][j] > avilable[j])
            {
                flag=1;
                break;
            }
        }


        if(flag==0)
        {
            printf("avilable after taking p%d\n",i);
            for(int j = 0; j < resource; j++)
            {
                avilable[j] = avilable[j]+allocation[i][j];
                cout<<avilable[j]<<" ";
            }
            printf("\n");
            visited[i] = true;
            result.push_back(i);
            total++;
        }
    }

    if(result.size() == process)
    {
        printf("DESIRED SEQUENCE\n");
        for(int i = 0; i < result.size(); i++)
        {
            cout<<"p"<<result[i]<<" ";
        }
    }
    else {
        printf("There is a deadlock\n");
        for(int i = 0; i < process; i++)
        {
            if(!visited[i])
                printf("Deadlock in p%d",i);
        }
    }

    return 0;
}
