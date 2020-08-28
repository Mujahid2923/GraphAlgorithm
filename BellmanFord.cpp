vector < ll > adj[ siz ],cost[ siz ] ;
ll n, m, x, y, z ;
ll dist[ siz ] ;

void Input()
{
    scanf( "%lld %lld", &n, &m ) ;
    for( int i = 0 ; i < m ; i ++ )
    {
        scanf( "%lld %lld %lld", &x, &y, &z ) ;
        adj[ x ].pb( y ) ;
        cost[ x ].pb( z ) ;
    }
}

bool Bellmanford( int s )
{
    for( int i = 1 ; i <= n ; i ++ ) dist[ i ] = INT_MAX ;
    dist[ s ] = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++  )
        {
            ll u = j ;
            for( int k = 0 ; k < adj[ u ].size() ; k ++ )
            {
                ll v = adj[ u ][ k ] ;
                ll w = cost[ u ][ k ] ;
                if( dist[ u ] + w < dist[ v ] ) dist[ v ] = dist[ u ] + w ;
            }
        }
    }

    for( int j = 1 ; j <= n ; j ++  )
    {
        ll u = j ;
        for( int k = 0 ; k < adj[ u ].size() ; k ++ )
        {
            ll v = adj[ u ][ k ] ;
            ll w = cost[ u ][ k ] ;
            if( dist[ u ] + w < dist[ v ] ) return false ;
        }
    }
    return true ;
}

void Calculation()
{
    if( !Bellmanford( 1 ) ) pf( "Negative cycle detected\n" ) ;
    else for( int i = 1 ; i <= n ; i ++ ) cout << dist[ i ] << endl ;
}

/*
4 4
1 2 4
1 4 5
4 3 3
3 2 -10

out - 0 -2 8 5

4 5
1 2 4
1 4 5
4 3 3
3 2 -10
2 4 5
out - Negative cycle detected
*/










int dis[ 105 ] ;

struct Node
{
    int u, v, w ;
    Node( int u, int v, int w )
    {
        this -> u = u ;
        this -> v = v ;
        this -> w = w ;
    }
    bool operator < ( const Node& p ) const {}
};

vector < Node > vec ;

int node, edge, s, cnt ;

void Bellmanford( int s )
{
    for( int i = 0 ; i <= node ; i ++ )
    {
        dis[ i ] = 100000010 ;
    }

    dis[ s ] = 0 ;

    for( int i = 1 ; i <= node ; i ++ )
    {
        for( int j = 0 ; j < edge ; j ++ )
        {
            int u = vec[ j ].u ;
            int v = vec[ j ].v ;
            int w = vec[ j ].w ;
            dis[ v ] = min( dis[ v ], dis[ u ] + w ) ;
        }
    }

    for( int j = 0 ; j < edge ; j ++ )
    {
        int u = vec[ j ].u ;
        int v = vec[ j ].v ;
        int w = vec[ j ].w ;
        if( w + dis[ u ] < dis[ v ] )
        {
            dis[ v ] = dis[ u ] + w ;
            cnt = 1 ;
            break ;
        }
    }
}


int main()
{
    cin >> node >> edge ;

    int u, v, w ;
    for( int i = 0 ; i < edge ; i ++ )
    {
        cin >> u >> v >> w ;
        vec.pb( Node( u, v, w  ) ) ;
    }

    cin >> s ;
    Bellmanford( s ) ;

    if( cnt )
    {
        cout<<"Negative cycle detected"<<endl;
        exit( 0 ) ;
    }
    for( int i = 1 ; i <= node ; i ++ )
    {
        cout << i << " = " << dis[ i ] << endl ;
    }
    return 0;
}

/*
4 4
1 2 4
1 4 5
4 3 3
3 2 -10
1

output:
1 = 0
2 = -2
3 = 8
4 = 5

4 5
1 2 4
1 4 5
4 3 3
3 2 -10
2 4 5
1
Negative cycle detected

*/
