///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define        zero(a)             memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

int node, edge, Time = 0 ;
vector< int > adj[ 200005 ] ;
int AP[ 200005 ] ;
int disc[ 200005 ] ;
int low[ 200005 ] ;


int DFS( int u, int p )
{
    disc[ u ] = low[ u ] = ++ Time ;
    int children = 0 ;

    for( int i = 0 ; i < adj[ u ].size() ; i ++ )
    {
        int v = adj[ u ][ i ] ;
        if( v == p )
        {
            continue ; ///we don't want to go back through the same path.
        }

        /// if we go back is because we found another way back

        if( !disc[ v ] )
        {
            children ++ ;
            DFS( v, u ) ;

            if( disc[ u ] <= low[ v ] )
            {
                AP[ u ] = 1 ;
            }

            low[ u ] = min( low[ u ], low[ v ] ) ; /// low[v] might be an ancestor of u
        }
        else /// if v was already discovered means that we found an ancestor
        {
            low[ u ] = min( low[ u ], disc[ v ] ) ; /// finds the ancestor with the least discovery time
        }
    }
    return children ;
}

int main()
{
    int a, b ;
    cin >> node >> edge ;
    for( int i = 0 ; i < edge ; i ++ )
    {
        cin >> a >> b ;
        adj[ a ].pb( b ) ;
        adj[ b ].pb( a ) ;
    }

    for( int i = 0 ; i <= node ; i ++ )
    {
        if( !disc[ i ] )
        {
            AP[ i ] = DFS( i, i ) > 1 ;
        }
    }

    for( int i = 0 ; i <= node ; i ++ )
    {
        if( AP[ i ] == 1 )
        {
            cout << i << " " ;
        }
    }

    return 0;
}

/*
8 9
1 2
1 3
2 3
3 4
4 5
5 6
5 7
6 7
6 8
output : 3 4 5 6


7 7
1 2
1 3
3 4
3 7
4 5
4 6
6 7
Out : 1 3 4
*/

///https://codeforces.com/blog/entry/71146








///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define        zero(a)             memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

int node, edge, Time = 0 ;
vector< int > adj[ 200005 ] ;
int articulationPoint[ 200005 ] ;
int visited[ 200005 ] ;
int parent[ 200005 ] ;
int d[ 200005 ] ;
int low[ 200005 ] ;


void FindArticulationPoint( int u )
{

    d[ u ] = low[ u ] = ++ Time ;
    visited[ u ] = 1 ;
    int childcount = 0 ;

    for( int i = 0 ; i < adj[ u ].size() ; i ++ )
    {
        int v = adj[ u ][ i ] ;
        if( visited[ v ] == 0 )
        {
            childcount ++ ;
            parent[ v ] = u ;
            FindArticulationPoint( v ) ;
            low[ u ] = min( low[ u ], low[ v ] ) ;

            if( childcount > 1 && parent[ u ] == -1 )
            {
                articulationPoint[ u ] = 1 ;
            }
            else if( d[ u ] <= low[ v ] && parent[ u ] != -1 )///remove equal for bridge
            {
                articulationPoint[ u ] = 1 ;
            }
        }
        else if( v != parent[ u ] )
        {
            low[ u ] = min( low[ u ],d[ v ] ) ; ///That means a child , backEdge
        }
    }
}

int main()
{
    int a , b ;
    cin >> node >> edge ;
    for( int i = 0 ; i < edge ; i ++ )
    {
        cin >> a >> b ;
        adj[ a ].pb( b ) ;
        adj[ b ].pb( a ) ;
    }

    for( int i = 1 ; i <= node ; i ++ )
    {
        parent[ i ] = -1 ;
    }

    for( int i = 1 ; i <= node ; i ++ )
    {
        if( visited[ i ] == 0 )
        {
            FindArticulationPoint( i ) ;
        }
    }

    for( int i = 1 ; i <= node ; i ++ )
    {
        if( articulationPoint[ i ] == 1 )
        {
            cout << i << " " ;
        }
    }

    return 0;
}

/*
8 9
1 2
1 3
2 3
3 4
4 5
5 6
5 7
6 7
6 8
output : 3 4 5 6


7 7
1 2
1 3
3 4
3 7
4 5
4 6
6 7
*/


