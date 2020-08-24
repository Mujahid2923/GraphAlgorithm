vector < int > adj[ 100005 ] ;

int n ;
ll parent[ 100005 ] ;
ll level[ 100005 ] ;
ll arr[ 100005 ][ 25 ] ;


void Reset()
{
    memset( arr, -1, sizeof arr ) ;
}

void Input()
{
    cin >> n ;
    for( int i = 1, x, y ; i < n ; i ++ )
    {
        cin >> x >> y ;
        adj[ x ].pb( y ) ;
        adj[ y ].pb( x ) ;
    }
}

void dfs( int u, int p, int lev )
{
    parent[ u ] = p ;
    level[ u ] = lev ;
    for( auto v : adj[ u ] )
    {
        if( v != p ) dfs( v, u, lev + 1 ) ;
    }
}

void build()
{
    for( int i = 0 ; i < n ; i ++ )
    {
        arr[ i ][ 0 ] = parent[ i ] ;
    }

    for( int j = 1 ; ( 1 << j ) < n ; j ++ )
    {
        for( int i = 0 ; i < n ; i ++ )
        {
            if( arr[ i ][ j - 1 ] != -1 )
            {
                arr[ i ][ j ] = arr[ arr[ i ][ j - 1 ] ][ j - 1 ] ;
            }
        }
    }
}

int query( int p, int q )
{
    if( level[ p ] < level[ q ] ) swap( p, q ) ;

    int log = 1 ;
    while( 1 )
    {
        if( ( 1 << ( log + 1 ) ) > level[ p ]  ) break ;
        log ++ ;
    }

    for( int i = log ; i >= 0 ; i -- )
    {
        if( level[ p ] - ( 1 << i ) >= level[ q ] ) p = arr[ p ][ i ] ;
    }

    if( p == q ) return p ;

    for( int i = log ; i >= 0 ; i -- )
    {
        if( arr[ p ][ i ] != -1 && arr[ p ][ i ] != arr[ q ][ i ] )
        {
            p = arr[ p ][ i ] ;
            q = arr[ q ][ i ] ;
        }
    }
    return parent[ p ] ;
}

void Calculation()
{
    dfs( 0, -1, 0 ) ;
    build() ;
    int p, q ;
    cin >> p >> q ;
    cout << query( p, q ) << endl ;
}


void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    int t ;
    //cin >> t ;
    t = 1 ;
    while( t-- ) solve() ;
    return 0 ;
}

/*
5
0 1
0 2
2 3
2 4

2 3 -> 2
2 4 -> 2
3 4 -> 2
1 4 -> 0

*/



/// https://open.kattis.com/problems/tourists

vector < ll > adj[ 200005 ] ;

ll n, x, y ;
ll level[ 200005 ] ;
ll parent[ 200005 ] ;
ll arr[ 200005 ][ 25 ] ;


void Reset()
{
    memset( arr, -1, sizeof arr ) ;
}

void Input()
{
    cin >> n ;
    for( int i = 1 ; i < n ; i ++ )
    {
        cin >> x >> y ;
        adj[ x ].pb( y ) ;
        adj[ y ].pb( x ) ;
    }
}

void dfs( int u, int p, int lev )
{
    parent[ u ] = p ;
    level[ u ] = lev ;
    for( auto v : adj[ u ] ) if( v != p ) dfs( v, u, lev + 1 ) ;
}

void build()
{
    for( int i = 1 ; i <= n ; i ++ ) arr[ i ][ 0 ] = parent[ i ] ;
    for( int j = 1 ; ( 1 << j ) < n ; j ++ )
    {
        for( int i = 1 ; i <= n ; i ++ )
        {
            if( arr[ i ][ j - 1 ] != -1 ) arr[ i ][ j ] = arr[ arr[ i ][ j - 1 ] ][ j - 1 ] ;
        }
    }
}

int query( int p, int q )
{
    if( level[ q ] > level[ p ] ) swap( p, q ) ;
    int L = 1 ;
    while( 1 )
    {
        if( ( 1 << ( L + 1 ) ) > level[ p ] ) break ;
        L ++ ;
    }
    for( int i = L ; i >= 0 ; i -- )
    {
        if( level[ p ] - ( 1 << i ) >= level[ q ] ) p = arr[ p ][ i ] ;
    }

    if( p == q ) return p ;

    for( int i = L ; i >= 0 ; i -- )
    {
        if( arr[ p ][ i ] != -1 && arr[ p ][ i ] != arr[ q ][ i ] )
        {
            p = arr[ p ][ i ] ;
            q = arr[ q ][ i ] ;
        }
    }
    return parent[ p ] ;
}
void Calculation()
{
    dfs( 1, -1, 0 ) ;
    build() ;
    ll sum = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = i + i ; j <= n ; j += i )
        {
            int par = query( i, j ) ;
            sum += level[ i ] + level[ j ] - 2 * level[ par ] + 1 ;
        }
    }
    cout << sum << endl ;
}
