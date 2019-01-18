#include<bits/stdc++.h>

///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

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

///--------------Graph Moves--------------------------------------
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


vector<int>v;
char s[20][20];
int visited[20][20];

bool isValid(int row,int col,int x,int y)
{
    if(x>=0 && x<row && y>=0 && y<col && visited[x][y]==0 && s[x][y]=='.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DFS(int row,int col,int x,int y)
{
    visited[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int xx=x+fx[i];
        int yy=y+fy[i];

        if(isValid(row,col,xx,yy))
        {
            DFS(row,col,xx,yy);
        }
    }
}

int main()
{
    int t,row,col,x,y;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int cnt=0;
        cin>>col>>row;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cin>>s[i][j];
            }
        }

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(s[i][j]=='@')
                {
                    x=i;
                    y=j;
                    break;
                }
            }
        }

        DFS(row,col,x,y);
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(visited[i][j]==1)
                {
                    cnt++;
                }
            }
        }

        pf("Case %d: %d\n",k,cnt);
        memset(visited,0,sizeof visited);

    }
    return 0;
}

/*
4

6 9

....#.

.....#

......

......

......

......

......

#@...#

.#..#.

11 9

.#.........

.#.#######.

.#.#.....#.

.#.#.###.#.

.#.#..@#.#.

.#.#####.#.

.#.......#.

.#########.

...........

11 6

..#..#..#..

..#..#..#..

..#..#..###

..#..#..#@.

..#..#..#..

..#..#..#..

7 7

..#.#..

..#.#..

###.###

...@...

###.###

..#.#..

..#.#..
*/
