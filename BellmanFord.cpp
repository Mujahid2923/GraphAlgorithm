///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
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
///#define          endl                   '\n'

///bool operator < ( const Node& p ) const{ return cost < p.cost ; }
///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = std::bitset<64>(n).to_string();
///---------------Order set-------------------
///template<typename T> using orderset =tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
///#include <ext/pb_ds/assoc_container.hpp>
///using namespace __gnu_pbds;
///*os.find_by_order(index) os.order_of_key(value)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

int dis[ 105 ] ;

struct Node
{
    int u, v, w ;
    Node( int u, int v, int w )
    {
        this -> u = u ;
        this -> v = v ;
        this -> w = w ;
    }
    bool operator < ( const Node& p ) const {}
};

vector < Node > vec ;

int node, edge, s, cnt ;

void Bellmanford( int s )
{
    for( int i = 0 ; i <= node ; i ++ )
    {
        dis[ i ] = 100000010 ;
    }

    dis[ s ] = 0 ;

    for( int i = 1 ; i <= node ; i ++ )
    {
        for( int j = 0 ; j < edge ; j ++ )
        {
            int u = vec[ j ].u ;
            int v = vec[ j ].v ;
            int w = vec[ j ].w ;
            dis[ v ] = min( dis[ v ], dis[ u ] + w ) ;
        }
    }

    for( int j = 0 ; j < edge ; j ++ )
    {
        int u = vec[ j ].u ;
        int v = vec[ j ].v ;
        int w = vec[ j ].w ;
        if( w + dis[ u ] < dis[ v ] )
        {
            dis[ v ] = dis[ u ] + w ;
            cnt = 1 ;
            break ;
        }
    }
}


int main()
{
    cin >> node >> edge ;

    int u, v, w ;
    for( int i = 0 ; i < edge ; i ++ )
    {
        cin >> u >> v >> w ;
        vec.pb( Node( u, v, w  ) ) ;
    }

    cin >> s ;
    Bellmanford( s ) ;

    if( cnt )
    {
        cout<<"Negative cycle detected"<<endl;
        exit( 0 ) ;
    }
    for( int i = 1 ; i <= node ; i ++ )
    {
        cout << i << " = " << dis[ i ] << endl ;
    }
    return 0;
}

/*
4 4
1 2 4
1 4 5
4 3 3
3 2 -10
1

output:
1 = 0
2 = -2
3 = 8
4 = 5

4 5
1 2 4
1 4 5
4 3 3
3 2 -10
2 4 5
1
Negative cycle detected

*/
