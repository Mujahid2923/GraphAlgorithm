typedef pair< int, pair<int,int>> pii ;

int parent[ 105 ] ;

vector < pii > vec ;

int Find( int r )
{
    if( r == parent[ r ] ) return r ;
    else return parent[ r ] = Find( parent[ r ] ) ;
}

int kruskal( int n )
{
    for( int i = 1 ; i <= n ; i ++ ) parent[ i ] = i ;

    int cnt = 0, sum = 0 ;

    for( int i = 0 ; i < vec.size() ; i ++ )
    {
        int u = Find( vec[ i ].second.first ) ;
        int v = Find( vec[ i ].second.second ) ;
        if( u != v )
        {
            parent[ u ] = v ;
            sum += vec[ i ].first ;
            cnt ++ ;
            if( cnt == n - 1 ) break ;
        }
    }
    return sum ;
}


-------------------------------------------------*****************-------------------------------------------------
ll node, edge ;
ll parent[ 100005 ] ;

struct Node
{
    ll node1, node2, cost ;
    Node( ll x, ll y, ll z )
    {
        node1 = x ;
        node2 = y ;
        cost = z;
    }

    bool operator < ( const Node& p ) const
    {
        return cost < p.cost ; //choto theke boro
    }
};

vector< Node > vec ;

ll Find( ll r )
{
    if( r == parent[ r ] ) return r ;
    else return parent[ r ] = Find( parent[ r ] ) ;
}

ll kruskal()
{
    for( int i = 1 ; i <= node ; i ++ )
    {
        parent[ i ] = i ;
    }

    ll cnt = 0, weight = 0 ;
    for( int i = 0 ; i < edge ; i ++ )
    {
        ll u = Find( vec[ i ].node1 ) ;
        ll v = Find( vec[ i ].node2 ) ;
        if( u != v )
        {
            parent[ u ] = v ;
            cnt ++ ;
            weight += vec[ i ].cost ;
            if( cnt == node - 1 ) break;
        }
    }
    return weight;
}

int main()
{
    ll a, b, c ;
    cin >> node >> edge ;
    for( int i = 0 ; i < edge ; i ++ )
    {
        cin >> a >> b >> c ;
        vec.pb( Node( a, b, c ) ) ;
    }

    sort( all( vec ) );
    cout<< kruskal() << endl ;
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

