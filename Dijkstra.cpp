#define          pll                    pair < ll, ll>
#define          siz                    100005

ll n, m, x, y, z ;
ll dist[ siz ], parent[ siz ] ;
vector < ll > adj[ siz ],cost[ 300005 ] ;
void Reset()
{
    for( int i = 0 ; i < siz ; i ++ ) dist[ i ] = INT_MAX ;
}

void Input()
{
    scanf( "%lld %lld", &n, &m ) ;
    for( int i = 0 ; i < m ; i ++ )
    {
        scanf( "%lld %lld %lld", &x, &y, &z ) ;
        adj[ x ].pb( y ) ;
        cost[ x ].pb( z ) ;
    }
}

void dijkstra( int s )
{
    priority_queue< pll,vector< pll >,greater< pll > > PQ ;
    PQ.push( { 0, s } ) ;
    dist[ s ] = 0 ;

    while( !PQ.empty() )
    {
        pll val = PQ.top() ;
        PQ.pop() ;

        int u = val.ss ;
        for( int i = 0 ; i < adj[ u ].size() ; i ++ )
        {
            int v = adj[ u ][ i ] ;
            if( dist[ u ] + cost[ u ][ i ] < dist[ v ] )
            {
                dist[ v ] = dist[ u ] + cost[ u ][ i ] ;
                PQ.push( { dist[ v ], v } ) ;
            }
        }
    }
}

void Calculation()
{
    dijkstra( 1 ) ;
    for( int i = 1 ; i <= n ; i ++ ) cout << dist[ i ] << endl ;
}


-----------------------------------*****************----------------------------------

#include<bits/stdc++.h>
using namespace std;

vector<int>graph[100005];
vector<int>cost[100005];

int distanc[100005];
int parent[100005];

struct node
{
    int u,w;
    node(int a,int b )
    {
        u=a;//node number
        w=b;//distance
    }
    bool operator <(const node &p) const
    {
        return w>p.w;///sort in ascending order
    }
};

void dijkstra(int s)
{
    for(int i=0; i<100005; i++)
    {
        distanc[i]=9999999;
        parent[i]=-1;
    }

    priority_queue<node>pq;
    pq.push(node(s,0));

    distanc[s]=0;

    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
        int u=top.u;

        for(int i=0; i<graph[u].size(); i++)
        {
            int v=graph[u][i];

            if(distanc[u]+cost[u][i] < distanc[v])
            {
                distanc[v]=distanc[u]+cost[u][i];
                pq.push(node(v,distanc[v]));
                parent[v]=u;
            }
        }
    }
}

int main()
{
    int n,e,a,b,w,s,des;
    int res;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        cin>>a>>b>>w;
        graph[a].push_back(b);
        cost[a].push_back(w);
    }

    cin>>s;
    dijkstra(s);

    for(int i=1; i<=n; i++)
    {
        cout<<i<<" = "<<distanc[i]<<endl;
    }

    cout<<"Enter till what you want to get destination"<<endl;
    cin>>des;
    cout<<"From "<<s<<" to "<<des<<" total destination is : "<<distanc[des]<<endl;

    /** path printing **/
    if(distanc[des] == -1)
    {
        cout<<"No way"<<endl;
    }
    else
    {
        vector<int>path;
        int p=n;

        while(p != -1)
        {
            path.push_back(p);
            p=parent[p];
        }
        reverse(path.begin(),path.end());

        cout<<"Shortest path is:"<<endl;
        for(int i=0; i<path.size(); i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*
4 4
1 2 2
1 3 5
2 3 1
3 4 3
1
4

Output : From 1 to 4 total destination is : 6
Shortest path is:
1 2 3 4

Full code with extra part:
https://paste.ubuntu.com/p/Xr93yBgJ48/?fbclid=IwAR09bPdsiijzBPLE-f4VU1OJSZjLstJQ6ezlDdXHHU-K-YXJzvvOT5BE-Pg
*/
