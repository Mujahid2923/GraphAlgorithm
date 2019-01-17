#include<bits/stdc++.h>
using namespace std;

vector<int>vec[10000];
int visited[10000];
vector<int>v;

void dfs(int s)
{
    if(visited[s]==1)
        return;
    visited[s]=1;
    v.push_back(s);

    for(int i=0; i<vec[s].size(); i++)
    {
        int v=vec[s][i];
        dfs(v);
    }
}

int main()
{
    int n,e,a,b,s;
    cin>>n>>e;
    memset(visited,0,sizeof visited);
    for(int i=0; i<e; i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    cin>>s;
    dfs(s);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;

}

/*
5 5
0 1
0 2
0 3
1 2
2 4
0
*/
///Output:0 1 2 4 3,,,starting with 0

/*
5 7
0 1
0 4
1 2
1 3
1 4
3 4
2 3
0
*/
///Output:0 1 2 3 4,,,starting with 0

