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

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


vector<int>adj[1000];
int start[1000];
int finish[1000];
int visited[1000];
int Time=0;

void dfs(int u)
{
    Time+=1;
    start[u]=Time;
    visited[u]=1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(visited[v]==0)
        {
            dfs(v);
        }
    }
    visited[u]=2;
    Time+=1;
    finish[u]=Time;
}

int main()
{
    zero(start);
    zero(finish);
    zero(visited);

    int node,edge,a,b;
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
    }

    for(int i=1; i<=node; i++)
    {
        if(visited[i]==white)
        {
            dfs(i);
        }
    }

    for(int i=1; i<=node; i++)
    {
        cout<<i<<" Start in : "<<start[i]<<" and Finish in : "<<finish[i]<<endl;
    }
    return 0;
}

/*
4 4
2 1
1 4
3 4
2 3

1 Start in : 1 and Finish in : 4
2 Start in : 5 and Finish in : 8
3 Start in : 6 and Finish in : 7
4 Start in : 2 and Finish in : 3

7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5
1 Start in : 1 and Finish in : 14
2 Start in : 2 and Finish in : 13
3 Start in : 3 and Finish in : 12
4 Start in : 4 and Finish in : 11
5 Start in : 5 and Finish in : 10
6 Start in : 6 and Finish in : 9
7 Start in : 7 and Finish in : 8

*/

