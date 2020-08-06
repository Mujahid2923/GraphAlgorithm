--------------------------********* dfs level with number of child of each node *********----------------------------
level :
-------
void dfs( int u , int lev )
{
    visited[ u ] = 1 ;
    for( auto v : adj[ u ] ) if( !visited[ v ] ) dfs( v , lev + 1 ) ;
    level[ u ] = lev ;
}

start & Finish time :
--------------------
int cnt = 0 ;
int start[ 200005 ] ;
int finish[ 200005 ] ;
int level[ 200005 ] ;

int dfs( int u, int p, int lev )
{
    start[ u ] = ++ cnt ;
    for( auto v : adj[ u ] )
    {
        if( v != p )
        {
            dfs( v, u, lev + 1 ) ;
        }
    }
    finish[ u ] = ++ cnt ;
    level[ u ] = lev ;
}

dfs( 1 , 0 , 0 ) ;
level - level[ i ] ;
number of  child -> ( finish[ i ] - start[ i ] ) / 2

    ----------------------------leaf number----------------------------
    void dfs( int u, int p, int w )
{
    child[ u ] = 0 ;
    int ok = 0 ;
    for( int i = 0 ; i < adj[ u ].size() ; i ++ )
    {
        int v = adj[ u ][ i ] ;
        int val = cost[ u ][ i ] ;
        if( v != p )
        {
            dfs( v , u , val ) ;
            ok ++ ;
            child[ u ] += child[ v ] ;
        }
    }
    if( !ok ) child[ u ] ++ ;
    arr[ u ] = w ;
}

-------------------------------------------------------------
-------------------------------****** bfs ********---------------------------------------


vector<int>adj[1000];
int visited[1000],level[1000];

void BFS(int s)
{
    memset(level,0,sizeof visited);
    queue<int>q;
    q.push(s);
    level[s]=0;
    visited[s]=1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                level[v]=level[u]+1;
                q.push(v);
                visited[v]=1;
            }
        }

    }
}

int main()
{
    int node,edge,a,b,s;
    scin2(node,edge);
    for(int i=0; i<edge; i++)
    {
        scin2(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    scin(s);
    BFS(s);
    for(int i=1; i<=node; i++)
    {
        pf("level of %d node is %d\n",i,level[i]);
    }
    return 0;
}

/*
5 4
1 2
1 3
2 4
2 5
1

Output:

level of 1 node is 0
level of 2 node is 1
level of 3 node is 1
level of 4 node is 2
level of 5 node is 2

*/
