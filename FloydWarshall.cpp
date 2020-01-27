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

vector < int > v ;
int arr[ 105 ][ 105 ] ;
int dist[ 105 ][ 105 ] ;
int Next[ 105 ][ 105 ] ;

void findPath( int i , int j )
{
    v.pb( i ) ;
    while( i != j )
    {
        i = Next[ i ][ j ] ;
        v.pb( i ) ;
    }
    for( auto x : v )
    {
        cout << x << " " ;
    }
}

int main()
{
    int n, e , a , b , w ;
    cin >> n ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++ )
        {
            arr[ i ][ j ] = INT_MAX ;
        }
        arr[ i ][ i ] = 0 ;
    }

    cin >> e ;
    for( int i = 1 ; i <= e ; i ++ )
    {
        cin >> a >> b >> w ;
        arr[ a ][ b ] = min( w , arr[ a ][ b ] ) ;
        //arr[ b ][ a ] = min( w , arr[ b ][ a ] ) ;
    }

    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++ )
        {
            dist[ i ][ j ] = arr[ i ][ j ] ;
            Next[ i ][ j ] = j ;
        }
    }

    for( int k = 1 ; k <= n ; k ++ )
    {
        for( int i = 1 ; i <= n ; i ++ )
        {
            for( int j = 1 ; j <= n ; j ++ )
            {
                if( dist[ i ][ k ] != INT_MAX && dist[ k ][ j ] != INT_MAX )
                {
                    if( dist[ i ][ k ] + dist[ k ][ j ] < dist[ i ][ j ] )
                    {
                        Next[ i ][ j ] = Next[ i ][ k ] ;
                        dist[ i ][ j ] = dist[ i ][ k ] + dist[ k ][ j ] ;
                    }

                }
            }
        }
    }
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++ )
        {
            cout << dist[ i ][ j ] << " " ;
        }
        cout << endl ;
    }

    int x , y ;
    cin >> x >> y ;
    findPath( x , y ) ;
    return 0 ;
}

/*

4 7
1 2 3
2 1 8
1 4 7
4 1 2
2 3 2
3 1 5
3 4 1

3 1
*/

