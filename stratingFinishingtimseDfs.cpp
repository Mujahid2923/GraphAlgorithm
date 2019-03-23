#include<bits/stdc++.h>
using namespace std;

#define white 0
#define gray 1
#define black 2
#define pb push_back

vector<int>adj[1000];
int start[1000];
int finish[1000];
int visited[1000];
int Time=0;

void dfs(int s)
{
    int u=s;
    Time+=1;
    start[u]=Time;
    visited[u]=gray;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(visited[v]==white)
        {
            dfs(v);
        }
    }
    visited[s]=black;
    Time+=1;
    finish[s]=Time;
}

int main()
{
    memset(start,0,sizeof start);
    memset(finish,0,sizeof finish);
    memset(visited,0,sizeof visited);

    int node,edge,a,b;
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
    }

    for(int i=1; i<=node; i++)
    {
        if(visited[i]==white)
        {
            dfs(i);
        }
    }

    for(int i=1; i<=node; i++)
    {
        cout<<i<<" Start in : "<<start[i]<<" and Finish in : "<<finish[i]<<endl;
    }
    return 0;
}

/*
4 4
2 1
1 4
3 4
2 3

1 Start in : 1 and Finish in : 4
2 Start in : 5 and Finish in : 8
3 Start in : 6 and Finish in : 7
4 Start in : 2 and Finish in : 3

7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5
1 Start in : 1 and Finish in : 14
2 Start in : 2 and Finish in : 13
3 Start in : 3 and Finish in : 12
4 Start in : 4 and Finish in : 11
5 Start in : 5 and Finish in : 10
6 Start in : 6 and Finish in : 9
7 Start in : 7 and Finish in : 8

*/
