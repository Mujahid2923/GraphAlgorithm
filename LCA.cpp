#include<bits/stdc++.h>
using namespace std;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          output                 freopen("output.txt","wt", stdout)
#define          ll                     long long int
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
vector < pair < string, string > > vec1, vec2 ;
vector < pll > vec, Vec ;
vector < int > adj[ 100005 ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
queue < ll > Q ;
stack < char > Stk ;
multiset < pll > S, B ;
vector < string > vs ;

///---------------------**********--------------------------------

int n ;
ll parent[ 100005 ] ;
ll level[ 100005 ] ;
ll arr[ 100005 ][ 25 ] ;


void Reset()
{
    memset( arr, -1, sizeof arr ) ;
}

void Input()
{
    cin >> n ;
    for( int i = 1, x, y ; i < n ; i ++ )
    {
        cin >> x >> y ;
        adj[ x ].pb( y ) ;
        adj[ y ].pb( x ) ;
    }
}

void dfs( int u, int p, int lev )
{
    parent[ u ] = p ;
    level[ u ] = lev ;
    for( auto v : adj[ u ] )
    {
        if( v != p ) dfs( v, u, lev + 1 ) ;
    }
}

void build()
{
    for( int i = 0 ; i < n ; i ++ )
    {
        arr[ i ][ 0 ] = parent[ i ] ;
    }

    for( int j = 1 ; ( 1 << j ) < n ; j ++ )
    {
        for( int i = 0 ; i < n ; i ++ )
        {
            if( arr[ i ][ j - 1 ] != -1 )
            {
                arr[ i ][ j ] = arr[ arr[ i ][ j - 1 ] ][ j - 1 ] ;
            }
        }
    }
}

int query( int p, int q )
{
    if( level[ p ] < level[ q ] ) swap( p, q ) ;

    int log = 1 ;
    while( 1 )
    {
        if( ( 1 << ( log + 1 ) ) > level[ p ]  ) break ;
        log ++ ;
    }

    for( int i = log ; i >= 0 ; i -- )
    {
        if( level[ p ] - ( 1 << i ) >= level[ q ] ) p = arr[ p ][ i ] ;
    }

    if( p == q ) return p ;

    for( int i = log ; i >= 0 ; i -- )
    {
        if( arr[ p ][ i ] != -1 && arr[ p ][ i ] != arr[ q ][ i ] )
        {
            p = arr[ p ][ i ] ;
            q = arr[ q ][ i ] ;
        }
    }
    return parent[ p ] ;
}

void Calculation()
{
    dfs( 0, -1, 0 ) ;
    build() ;
    int p, q ;
    cin >> p >> q ;
    cout << query( p, q ) << endl ;
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
    //cin >> t ;
    t = 1 ;
    while( t-- ) solve() ;
    return 0 ;
}

/*
5
0 1
0 2
2 3
2 4

2 3 -> 2
2 4 -> 2
3 4 -> 2
1 4 -> 0

*/

