#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
int visited[100];
vector<int>e;
int arr[100];

int main()
{
    memset(visited,0,sizeof visited);
    memset(arr,0,sizeof arr);
    int node,edge,a,b;
    cin>>node>>edge;
    queue<int>q;

    for(int i=1; i<=edge; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        arr[b]++;
    }

    for(int i=1; i<=node; i++)
    {
        if(arr[i]==0)
        {
            visited[i]=1;
            q.push(i);
            e.push_back(i);
        }
    }


    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        for(int j=0; j<adj[x].size(); j++)
        {
            int v=adj[x][j];
            arr[v]--;
            cout<<v<<" "<<arr[v]<<endl;
            if( arr[v] == 0 && visited[v] == 0 ){
                e.push_back(v);
                visited[v]=1;
                q.push(v);
            }
        }
    }

    for(int i=1; i<=node; i++)
    {
        if(arr[i]!=0)
        {
            cout<<"cycle in the loop"<<endl;
            return 0;
        }
    }

    for(int i=0; i<e.size(); i++)
    {
        cout<<e[i]<<" ";
    }
    return 0;
}
/*
6 7
1 2
2 3
2 4
2 6
4 3
6 5
1 5
*/
