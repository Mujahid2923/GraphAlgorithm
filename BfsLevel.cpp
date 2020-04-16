--------------------------********* dfs level with number of child of each node *********----------------------------
int cnt = 0 ;
int start[ 200005 ] ;
int finish[ 200005 ] ;
int level[ 200005 ] ;

int dfs( int u, int p, int lev )
{
    start[ u ] = ++ cnt ;
    for( auto v : adj[ u ] )
    {
        if( v != p )
        {
            dfs( v, u, lev + 1 ) ;
        }
    }
    finish[ u ] = ++ cnt ;
    level[ u ] = lev ;
}

dfs( 1 , 0 , 0 ) ;


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

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


vector<int>adj[1000];
int visited[1000],level[1000];

void BFS(int s)
{
    memset(level,0,sizeof visited);
    queue<int>q;
    q.push(s);
    level[s]=0;
    visited[s]=1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                level[v]=level[u]+1;
                q.push(v);
                visited[v]=1;
            }
        }

    }
}

int main()
{
    int node,edge,a,b,s;
    scin2(node,edge);
    for(int i=0; i<edge; i++)
    {
        scin2(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    scin(s);
    BFS(s);
    for(int i=1; i<=node; i++)
    {
        pf("level of %d node is %d\n",i,level[i]);
    }
    return 0;
}

/*
5 4
1 2
1 3
2 4
2 5
1

Output:

level of 1 node is 0
level of 2 node is 1
level of 3 node is 1
level of 4 node is 2
level of 5 node is 2

*/
