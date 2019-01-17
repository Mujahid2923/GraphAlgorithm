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
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

vector<int>adj[1000];
int visited[1000],parent[1000];
vi v;

void BFS(int s)
{
    memset(visited,0,sizeof visited);
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    parent[s]=-1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                Q.push(v);
                parent[v]=u;
            }
        }
    }
}

int main()
{
    int node,edge,a,b;
    scin2(node,edge);
    for(int i=0; i<edge; i++ )
    {
        scin2(a,b);
        adj[a].push_back(b);
        //adj[b].push_back(a);
    }
    int s,d;
    scin2(s,d);
    BFS(s);

    if(visited[d]==0)
    {
        cout<<"No path"<<endl;
    }
    else
    {
        for(int i=d; i!=-1; i=parent[i])
        {
            v.push_back(i);
        }
        reverse(v.begin(),v.end());
        printf("Path : ");
        for(auto x : v)
            cout<<x<<" ";
    }
    return 0;
}
/*
directional
6 7
1 4
1 2
2 3
4 5
3 5
4 5
5 6
1 6
*/
///Output:1 4 5 6

/*
Not directional
10 10
0 1
0 3
1 2
3 4
3 7
4 5
4 6
4 7
5 6
6 7
0 6
*/
///Output:2 1 0 3 4 6

