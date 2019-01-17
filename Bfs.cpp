#include<bits/stdc++.h>
using namespace std;

vector<int> vec [100000];
int visited[100000];

void BFS(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=1;

    while(!q.empty())
    {
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            if(visited[v]==0)
            {
                q.push(v);
                visited[v]=1;
            }
        }
    }
}

int main()
{
    int node,edge;
    int a,b;
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int s;
    cin>>s;
    BFS(s);
    return 0;
}

/*
6 7
1 2
1 3
2 4
2 5
3 5
4 6
5 6
1
*/
///Output:1 2 3 4 5 6
