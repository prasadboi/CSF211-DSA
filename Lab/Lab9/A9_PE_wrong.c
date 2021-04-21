#include <stdio.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0

void print_array(ll arr[], ll length)
{
    for (ll i = 0; i < length; i++)
    {
        printf("i : %lld = %lld || ", i, arr[i]);
    }
    printf("\n");
}

// function to create an adjacency_matrix
void adjacency_matrix(ll vert, ll edge, ll adj_mat[vert][vert])
{
    //printf("creating adjacency matrix, with vert = %lld, edges = %lld\n",vert, edge);
    ll EDGE_BEG, EDGE_END;
    for (int i = 0; i <vert; i++)
    {
        for (int j = 0; j < vert; j++)
        {
            adj_mat[i][j] = 0;
        }
    }


    for(ll i = 0; i < edge; i++)
    {
        //printf("edge number %lld : ", i+1);
        scanf("%lld%lld", &EDGE_BEG, &EDGE_END);
        //printf("%d, %d\n", EDGE_BEG, EDGE_END);
        adj_mat[EDGE_BEG-1][EDGE_END-1] = 1;
        //adj_mat[EDGE_END][EDGE_BEG] = 1;
    }
}

ll find_parent(ll u, ll vert, ll adj_mat[vert][vert])
{
    ll parent = -1;
    for (ll i = 0; i < vert; i++)
    {
        if(adj_mat[i][u] == 1)
        {
            parent = i;
            //printf("parent of %lld is %lld\n", u, i);
            break;
        }
    }
    return parent;
}

void path_bw_2_nodes(ll u, ll v, ll vert, ll adj_mat[vert][vert], ll path_uv[])
{
    for (ll i = 0; i < vert; i++)
    {
        path_uv[i] = -1;
    }
    
    ll start_u = u;
    ll root_path_u[vert];
    ll count_u = 0;

    ll start_v = v;
    ll root_path_v[vert];
    ll count_v = 0;

    ll LCA;
    for(ll i = 0; i < vert; i++)
    {
        root_path_u[i] = -25;
        root_path_v[i] = -2;
    }

    BOOL flag = FALSE;

    // storing paths from root those nodes respectively
    while(start_u >= 0)
    {
        root_path_u[count_u] = start_u;
        count_u++;
        start_u = find_parent(start_u, vert, adj_mat);
    }
    while(start_v >= 0)
    {
        root_path_v[count_v] = start_v;
        count_v++;
        start_v = find_parent(start_v,vert, adj_mat);
    }
    //print_array(root_path_u, vert);
    //print_array(root_path_v, vert);

    for (ll i = 0; i < vert; i++)
    {
        for (ll j = 0; j < vert; j++)
        {
            //printf("u_path:  %lld\n", root_path_u[i]);
            //printf("v_path:  %lld\n", root_path_v[j]);
            if(root_path_u[i] == root_path_v[j])
            {
                //printf("found the LCA  = %lld!!!\n", root_path_u[i]);
                flag = TRUE;
                LCA = root_path_u[i];
                
                break;
            }
            /*else
                printf("not the LCA !!!\n");*/
        }
        if(flag == TRUE)
            break;
    }

    ll k = 0;
    for (; root_path_u[k] != LCA; k++)
    {
        path_uv[k] = root_path_u[k];
    }
    path_uv[k] = LCA;
    k++;
    for (ll x = 0; root_path_v[x] != LCA; k++, x++)
    {
        path_uv[k] = root_path_v[x];
    }
}

int main(int argc, char const *argv[])
{
    ll count = 0;
    ll N, x, y;
    scanf("%lld%lld %lld", &N, &x, &y);
    ll adj_mat[N][N];
    ll path[N];
    adjacency_matrix(N, N-1, adj_mat);
    //path_bw_2_nodes(2, 1, N, adj_mat, path);
    //print_array(path, N);
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if(i == j)
                j++;
            if(j == N)  
                break;
            //printf("i : %lld, j : %lld\n", i, j);
            BOOL flag = TRUE;
            path_bw_2_nodes(i, j, N, adj_mat, path);
            //print_array(path, N);
            for (ll k = 0; k < N; k++)
            {
                if(path[k] == x-1)
                {
                    //ll t = k;
                    for(; k < N; k++)
                    {
                        if(path[k] == y-1)
                        {flag = FALSE;
                        break;}
                    }
                }
            }
            if(flag == TRUE)
            {
                count++;
                //printf("count : %lld \n", count);
            }
            
        }
    
    }
    printf("%lld", count);
    return 0;
}
