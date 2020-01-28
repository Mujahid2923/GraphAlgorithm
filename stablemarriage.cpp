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

int n, m ;
int M[ 105 ][ 105 ], W[ 105 ][ 105 ], M2W[ 105 ], W2M[ 105 ], P[ 105 ] ;

void stableMarriage()
{
    memset( W2M, -1, sizeof W2M ) ;
    for( int i = 0 ; i < m ; i ++ )
    {
        int man = i ;
        while( man >= 0 )
        {
            int woman ;
            while( 1 )
            {
                woman = M[ man ][ P[ man ] ++ ] ;

                if( W2M[ woman ] < 0 || W[ woman ][ man ] > W[ woman ][ W2M[ woman ] ] )
                {
                    break ;
                }
            }
            //cout << i << " " << man << " " << woman << " " << M2W[ man ] << " " << W2M[ woman ] << endl ;

            int x = W2M[ woman ] ;
            W2M[ woman ] = man ;
            M2W[ man ] = woman ;
            man = x ;
        }
        //cout << M2W[ i ] << " " << W2M[ i ] << endl ;
    }
}

int main()
{
    cin >> m >> n ;
    for( int i = 0 ; i < m ; i ++ )
    {
        for( int j = 0 ; j < n ; j ++ )
        {
            cin >> M[ i ][ j ] ;
        }
    }

    for( int i = m ; i < 2 * m ; i ++ )
    {
        int attractiveness = m - 1, x ;
        for( int j = 0 ; j < n ; j ++ )
        {
            cin >> x ;
            W[ i ][ x ] = attractiveness -- ;
        }
    }

    stableMarriage() ;

    cout << "Man" << " " << "Woman" << endl ;
    for( int i = 0 ; i < m ; i ++ )
    {
        cout << i << "     " << M2W[ i ] << endl ;
    }

    return 0 ;
}

/*

A person has an integer preference for each of the persons of the opposite
 * sex, produces a matching of each man to some woman. The matching will follow:
 *          - Each man is assigned to a different woman (n must be at least m)
 *          - No two couples M1W1 and M2W2 will be unstable.
 * Two couples are unstable if (M1 prefers W2 over W1 and W1 prefers M2 over M1)
 * INPUT: m – number of man, n – number of woman (must be at least as large as m)
 *          - M[i][]: the list of women in order of decreasing preference of man i
 *          - W[j][i]: the attractiveness of i to j.
 * OUTPUTS: - M2W[]: the mate of man i (always between 0 and n-1)
 *          - W2M[]: the mate of woman j (or -1 if single)


4 4

7 5 6 4
5 4 6 7
4 5 6 7
4 5 6 7

1 0 3 2
0 1 2 3
0 1 2 3
0 1 2 3

*/


