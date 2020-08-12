----------------------------------- Cycle in 2D grid ---------------------------------------------------
 void dfs( int x, int y, int par_x, int par_y , char ch )
{
    visited[ x ][ y ] = 1 ;
    for( int i = 0 ; i < 4 ; i ++ )
    {
        int xx = x + fx[ i ] ;
        int yy = y + fy[ i ] ;

        if( xx >= 1 && xx <= row && yy >= 1 && yy <= col && s[ xx ][ yy ] == ch )
        {
            if( !visited[ xx ][ yy ] )
            {
                dfs( xx, yy, x, y, ch ) ;
            }
            else if( visited[ xx ][ yy ] && !( par_x == xx && par_y == yy ) )
            {
                ok = 1 ;
                return ;
            }
        }

    }
}

void Calculation()
{
    for( int i = 1 ; i <= row ; i ++ )
    {
        for( int j = 1 ; j <= col ; j ++ )
        {
            if( !visited[ i ][ j ] )
            {
                dfs( i, j, -1, -1, s[ i ][ j ] ) ;
                if( ok )
                {
                    cout << "Yes" << endl ;
                    return ;
                }
            }
        }
    }
    cout << "No" << endl ;
}


--------------------------------------------------------------------------------------------------------


int ok=0;

void checkCycle(int u)
{
    visited[u]=1;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(visited[v]==0)
        {
            checkCycle(v);
        }
        else if(visited[v]==1)
        {
            ok=1; //Cycle
            return;
        }
    }
    visited[u]=2;
}
