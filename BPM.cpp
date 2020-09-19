/// http://lightoj.com/volume_showproblem.php?problem=1201

#include<bits/stdc++.h>
using namespace std;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          output                 freopen("output.txt","wt", stdout)
#define          ld                     long double
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          pf                     printf
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
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

///--------------------**********----------------------------------

vector < ll > v, v1, v2, v3, v4 ;
vector < pii > vec ;
vector < int > adj[ 1005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < int > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;
deque < ll > A ;

///---------------------**********--------------------------------

int n, m, x, y, test ;
int match[ 1005 ] ;

void Reset()
{
    for( int i = 1 ; i <= 1000 ; i ++ )
    {
        adj[ i ].clear() ;
        match[ i ] = -1 ;
    }
}

void Input()
{
    scanf( "%d %d", &n, &m ) ;
    for( int i = 1 ; i <= m ; i ++ )
    {
        scanf( "%d %d", &x, &y ) ;
        adj[ x ].pb( y ) ;
        adj[ y ].pb( x ) ;
    }
}

int dfs( int u, int p )
{
    for( auto v : adj[ u ] )
    {
        if( v != p )
        {
            if( match[ v ] == -1 || dfs( match[ v ], v ) )
            {
                match[ v ] = u ;
                match[ u ] = v ;
                return 1 ;
            }
        }
    }
    return 0 ;
}

int bpm()
{
    int cnt = 0 ;
    for( int i = 1 ; i <= n ; i ++ ) if( match[ i ] != -1 || !dfs( i, -1 ) ) cnt ++ ;
    return cnt ;
}

void Calculation()
{
    printf( "Case %d: %d\n", ++ test, bpm() ) ;
    for( int i = 1 ; i <= n ; i ++ ) cout << i << " " << match[ i ] << endl ;
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    int t ;
    scanf( "%d", &t ) ;
    while( t-- ) solve() ;
    return 0 ;
}

/*

10 9
8 7
9 7
7 1
6 10
1 6
1 3
1 2
2 4
4 5

*/

