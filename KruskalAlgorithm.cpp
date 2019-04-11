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
#define        scin3(x,y,z)        scanf("%d %d %d",&(x),&(y),&(z))
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

int node,edge;
int parent[100005];

struct Node
{
    int a,b,w;
    Node(int x,int y,int z)
    {
        a=x;
        b=y;
        w=z;
    }
    bool operator < (const Node& p) const
    {
        return w<p.w;
    }
};

vector<Node>vec;

int Find(int r)
{
    if(r==parent[r])
        return r;
    else
        return parent[r]=Find(parent[r]);
}

int mst()
{
    for(int i=1; i<=node; i++)
    {
        parent[i]=i;
    }

    int cnt=0,weight=0;
    for(int i=0; i<edge; i++)
    {
        int u=Find(vec[i].a);
        int v=Find(vec[i].b);
        if(u!=v)
        {
            parent[u]=v;
            cnt++;
            weight+=vec[i].w;
            if(cnt==node-1)
                break;
        }
    }
    return weight;
}

int main()
{
    int a,b,w;
    scin2(node,edge);
    for(int i=0; i<edge; i++)
    {
        scin3(a,b,w);
        vec.pb(Node(a,b,w));
    }
    sort(vec.begin(),vec.end());
    cout<<mst()<<endl;
    return 0;
}

/*
5 7
1 2 7
1 3 4
1 4 1
2 4 8
3 4 3
2 5 6
4 5 6
Output:16

6 9
1 2 6
1 5 5
2 5 7
2 3 1
5 4 14
3 5 8
3 6 2
3 4 5
4 6 3

Output:17
*/
