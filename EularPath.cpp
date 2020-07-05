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
vector < ll > adj[ 26 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < ll > st, st1, st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S ;


///---------------------**********--------------------------------
string s ;
ll n, m, cnt ;
int visited[ 26 ] ;
int In[ 26 ] ;
int Out[ 26 ] ;
int arr[ 26 ][ 26 ] ;

void Reset()
{
    st.clear() ;
    zero( In ) ;
    zero( Out ) ;
    for( int i = 0 ; i < 26 ; i ++ ) adj[ i ].clear() ;
}

void Input()
{
    cin >> n ;
    for( ll i = 0, x , y ; i < n ; i ++ )
    {
        cin >> s ;
        x = s[ 0 ] - 'a' ;
        y = s[ s.size() - 1 ] - 'a' ;
        st.insert( x ) ; st.insert( y ) ;
        In[ x ] ++ ;
        Out[ y ] ++ ;
        adj[ x ].pb( y ) ;
    }
}

void dfs( int s )
{
    cnt ++ ;
    visited[ s ] = 1 ;
    for( auto v : adj[ s ] )
    {
        if( !visited[ v ] ) dfs( v ) ;
    }
}

void Calculation()
{
    for( int i = 0 ; i < 26 ; i ++ )
    {
        if( abs( In[ i ] - Out[ i ]  ) > 1 )
        {
            cout << "The door cannot be opened." << endl ;
            return ;
        }
    }

    for( int i = 0 ; i < 26 ; i ++ )
    {
        zero( visited ) ;
        cnt = 0 ;
        dfs( i ) ;
        if( cnt == st.size() )
        {
            cout << "Ordering is possible." << endl ;
            return ;
        }
    }

    cout << "The door cannot be opened." << endl ;
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
    cin >> t ;
    //t = 1 ;
    while( t-- )
    {
        solve() ;
    }
    return 0 ;
}

/// Eular path
///https://www.spoj.com/problems/WORDS1/
///https://www.youtube.com/watch?v=REfC1-igKHQ

