/*
input :
    4 //number of edges
    1 3 //input edges
    1 2
    3 4
    4 5
    1 //starting
*/

/*Author : Rajob Raihan Monmoy
Date :
Email : iammonmoy@gmail.com
*/
#include <bits/stdc++.h>

#define ll long long int
#define ul unsigned long long int

#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d %d", &a, &b)
#define getIII(a,b,c) scanf("%d %d %d", &a, &b, &c)

#define getC(a) scanf("%c",&a)

#define chkII(a,b) cout<<a<<" "<<b<<endl;
#define chkIII(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;

#define ii pair<int,int>
#define pb push_back
#define All(x) (x.begin(),x.end())
#define mset(x,m) memset(x,m,sizeof(x))
#define xx first
#define yy second
#define mp make_pair

#define rep(i,a,b) for(int i = a; i < b; i++)
#define per(i,a,b) for(int i = b-1; i >= a; i--)

#define inf 1e9
#define MAX
#define N 1000

//direction array
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};

//in the limit
int inbound(int n, int m, int x, int y) { if(x >= 0 && x < n && y >= 0 && y < m) return 1; return 0;}

using namespace std;

vector<int>edge[N];
bool visited[N];
vector<int>d(N), parent(N);
queue<int>q;

void bfs(int start)
{
    mset(visited,false);

    q.push(start);
    visited[start] = true;
    d[start] = 0;
    parent[start] = -1; //parent of start node is no one

    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(int i = 0; i < edge[top].size(); i++)
        {
            int newNode = edge[top][i];
            if(!visited[newNode])
            {
                visited[newNode] = true;
                parent[newNode] = top;
                d[newNode] = d[top] + 1;
                q.push(newNode);
            }
        }
    }
}
int main()
{
    int n,x,y,start;
    scanf("%d", &n); //scan the number of query
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        edge[x].pb(y);
        edge[y].pb(x);
    }

    scanf("%d", &start);

    bfs(start);

    return 0;
}
