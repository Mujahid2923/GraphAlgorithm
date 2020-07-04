///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          eb                     emplace_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scin3(x,y,z)           scanf("%d %d %d",&(x),&(y),&(z))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          scln3(x,y,z)           scanf("%lld %lld %lld",&(x),&(y),&(z))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     acos(-1.0)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Min(v)                 *min_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;
#define          segment_tree           int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;

/// cout << fixed << setprecision( 9 ) << n << endl ;

///sum accumulate( v.begin(), v.begin() + k, 0LL )///bool operator < ( const Node& p ) const{ return cost < p.cost ; }
///priority_queue<int,vector<int>,greater<int> >pq;///std::set<ll, std::greater<ll> > Set;///string str = "abcdefghijklmnopqrstuvwxyz";///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = bitset<64>( n ).to_string() ; ll val =  bitset< 64 >( s ).to_ullong() ;

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0}; ///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move ///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move ///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


///--------------------**********----------------------------------

vector < ll > v, v1, v2, v3, v4 ;
vector < pair < ll, ll > > vec1, vec2 ;
vector < pll > vec ;
vector < ll > adj[ 10005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < ll > st1,st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------
string s ;
int n, m ;
priority_queue<int,vector<int>,greater<int> > PQ ;

int arr[ 10005 ] ;

void Reset()
{

}

void Input()
{
    cin >> n >> m ;
    for( int i = 0, a, b ; i < m ; i ++ )
    {
        cin >> a >> b ; adj[ a ].pb( b ) ; arr[ b ] ++ ;
    }
}



void Calculation()
{
    for( int i = 1 ; i <= n ; i ++ ) if( !arr[ i ] ) PQ.push( i ) ;
    while( !PQ.empty() )
    {
        int u = PQ.top() ;
        PQ.pop() ;
        v.pb( u ) ;

        for( auto v : adj[ u ] )
        {
            arr[ v ] -- ;
            if( !arr[ v ] ) PQ.push( v ) ;
        }
    }
    for( int i = 1 ; i <= n ; i ++ )
    {
        if( arr[ i ] != 0 )
        {
            cout << "Sandro fails." << endl ;
            return ;
        }
    }

    for( auto x : v )
    {
        cout << x << " " ;
    }
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    FaRaBi ;
    int t ;
    //cin >> t ;
    t = 1 ;
    while( t-- )
    {
        solve() ;
    }
    return 0 ;
}


----------------------------------------**************************---------------------------------------------------------


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
