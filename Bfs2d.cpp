///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ull                    unsigned long long int
#define          db                     double
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
#define          scin3(x,y,z)           scanf("%d %d %d",&(x),&(y),&(z))
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
#define          PI                     3.141592653589793238462643
#define          rep( i , a , b )       for( i=a ; i<b ; i++)
#define          rev( i , a , b )       for( i=a ; i>=b ; i--)
#define          repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define          RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          get_pos(c,x)           (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          CASEL(t)               printf("Case %d:\n",t)
#define          Unique(X)             (X).erase(unique(all(X)),(X).end())

///priority_queue<int,vector<int>,greater<int> >pq;

///---------------Order set-------------------
///template<typename T> using orderset =tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
///#include <ext/pb_ds/assoc_container.hpp>
///using namespace __gnu_pbds;
///*os.find_by_order(index) os.order_of_key(value)

///--------------Graph Moves--------------------------------------
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
///sort( all( v ) ) ;

char s[ 200 ][ 200 ] ;
int visited[ 200 ][ 200 ] ;
int level[ 200 ][ 200 ] ;
int row, col ;

bool isvalid(int x,int y)
{
    if(x >= 0 && x < row && y >= 0 && y < col && s[ x ][ y ] != '#' && s[ x ][ y ] != 'm' && visited[ x ][ y ] == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BFS( int x, int y )
{
    zero( visited ) ;
    zero( level ) ;

    queue< pii > Q ;
    Q.push( mp( x, y ) ) ;
    visited[ x ][ y ] = 1 ;

    while( !Q.empty() )
    {
        int a = Q.front().first;
        int b = Q.front().second;
        Q.pop() ;

        for( int i = 0 ; i < 4 ; i ++ )
        {
            int xx = a + fx[ i ] ;
            int yy = b + fy[ i ] ;

            if( isvalid( xx, yy ) )
            {
                level[ xx ][ yy ] = level[ a ][ b ] + 1 ;
                visited[ xx ][ yy ] = 1 ;
                Q.push( mp( xx, yy ) ) ;
            }
        }

    }
}

int main()
{
    int t, x1, x2, x3, x4, y1, y2, y3, y4 ;
    scin(t);
    for( int k = 1 ; k <= t ; k ++ )
    {
        scin2(row,col);

        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                cin >> s[ i ][ j ] ;
                if( s[ i ][ j ] == 'a' )
                {
                    x1 = i ;
                    y1 = j ;
                }
                if( s[ i ][ j ] == 'b' )
                {
                    x2=i;
                    y2=j;
                }
                if( s[ i ][ j ] == 'c' )
                {
                    x3=i;
                    y3=j;
                }
                if( s[ i ][ j ] == 'h' )
                {
                    x4=i;
                    y4=j;
                }
            }
        }
        BFS( x1, y1 ) ;
        int a = level[ x4 ][ y4 ] ;
        BFS( x2, y2 ) ;
        int b = level[ x4 ][ y4 ] ;
        BFS( x3, y3 ) ;
        int c = level[ x4 ][ y4 ] ;

        pf("Case %d: %d\n", k, max3( a, b, c ) ) ;
    }
    return 0;
}
///Loj-1238
