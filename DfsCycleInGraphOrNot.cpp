#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
int visited[100];
int ok=0;

void checkCycle(int u)
{
    visited[u]=1;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(visited[v]==0)
        {
            checkCycle(v);
        }
        else if(visited[v]==1)
        {
            ok=1;
            return;
        }
    }
    visited[u]=2;
}

int main()
{
    int node,edge;

    cin>>node>>edge;
    int a,b;
    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        //adj[b].push_back(a);
    }

    for(int i=0; i<edge; i++)
    {
        visited[i]=0;
    }

    int s;
    cin>>s;
    checkCycle(s);
    if(ok==1)
    {
        cout<<"Cycle"<<endl;
    }
    else
    {
        cout<<"Not Cycle"<<endl;
    }
    return 0;
}

/*
5 5
1 2
2 3
3 1
3 4
1 5
1
output:
Cycle
*/
