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

int visited[ 105 ] ;
int parent[ 105 ] ;
int cost[ 105 ][ 105 ] ;
vector < int > adj [ 105 ] ;
vector < int > vec ;

int bfs( int s, int d )
{
    visited[ s ] = 1 ;
    parent[ s ] = -1 ;
    queue < int > Q ;
    Q.push( s ) ;

    while( !Q.empty() )
    {
        int u = Q.front() ;
        Q.pop() ;

        if( u == d )
        {
            return 1 ;
        }

        for( int i = 0 ; i < adj[ u ].size() ; i ++ )
        {
            int v = adj[ u ][ i ] ;

            if( visited[ v ] == 0 && cost[ u ][ v ] > 0 )
            {
                visited[ v ] = 1 ;
                parent[ v ] = u ;
                Q.push( v ) ;
            }
        }
    }
    return 0 ;
}

int main()
{
    int n, e, a, b, w, s, d ;
    cin >> n >> e ;
    for( int i = 0 ; i < e ; i ++ )
    {
        cin >> a >> b >> w ;
        adj[ a ].pb( b ) ;
        cost[ a ][ b ] = w ;
    }

    cin >> s >> d ;
    int ans = 0 ;
    while( bfs( s, d ) )
    {
        int val = INT_MAX ;
        for( int i = d ; i != -1 ; i = parent[ i ] )
        {
            vec.pb( i ) ;
        }

        reverse( all( vec ) ) ;
        for( int i = 0 ; i < vec.size() - 1 ; i ++ )
        {
            int u = vec[ i ] ;
            int v = vec[ i + 1 ] ;
            val = min( val, cost[ u ][ v ] ) ;
        }

        // cout << val << endl ;

        ans += val ;

        for( int i = 0 ; i < vec.size() - 1 ; i ++ )
        {
            int u = vec[ i ] ;
            int v = vec[ i + 1 ] ;
            cost[ u ][ v ] -= val ;
            cost[ v ][ u ] += val ;
            adj[ v ].pb( u ) ;
        }

        vec.clear() ;
        zero( visited ) ;
        zero( parent ) ;
    }
    cout << ans << endl ;
    return 0 ;
}


/*

6 7
1 2 2
1 3 5
2 4 3
2 5 1
3 4 3
5 6 4
4 6 4
1 6

output :
5

*/
