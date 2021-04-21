#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define ll long long int
int vert;
int edge;
int visited[N];
int dfs_ctr = 0;


void adjacency_mat(int adj_mat[vert][vert])
{
    int EDGE_BEG, EDGE_END;

    for (int i = 0; i < vert; i++)
    {
        for (int j = 0; j < vert; j++)
        {
            adj_mat[i][j] = 0;
        }
    }
    for(int i = 0; i < edge; i++)
    {
        scanf("%d%d", &EDGE_BEG, &EDGE_END);
        //printf("%d, %d\n", EDGE_BEG, EDGE_END);
        adj_mat[EDGE_BEG][EDGE_END] = 1;
        adj_mat[EDGE_END][EDGE_BEG] = 1;
    }  
}

// queue
struct node
{
    int val;
    struct node* next;
};

struct node* create_node(int val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct node** head, struct node** last, int val)
{
    struct node* newNode = create_node(val);

    // in case the queue is empty
    if((*last) == NULL)
    {
        (*head) = newNode;
        (*last) = newNode;
        return;
    }

    // if the queue is not empty
    newNode->next = (*last)->next;
    (*last) = newNode;
    return;
}

int dequeue(struct node** head, struct node** last)
{
    if((*last)==NULL)
    {
        return INT_MIN;
    }
    else if((*last) == (*head))
    {
        int x = (*head)->val;
        struct node* temp = (*head);
        (*head) = NULL;
        (*last) = NULL;
        free(temp);
        return x;
    }
    int x = (*head)->val;
    struct node* temp = (*head);
    (*head) = NULL;
    (*last) = NULL;
    free(temp);
    return x;
}


void printMat(int n, int adj_mat[vert][vert])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
        
    }
    
}

void DFS(int adj_mat[vert][vert], int i)
{
    visited[i] = 1;
    dfs_ctr++;
    for (int j = 0; j < vert; j++)
    {
        if(adj_mat[i][j] == 1)
        {
            if (visited[j] == 0)
            {
                DFS(adj_mat, j);
            }       
        }
    }
}

void BFS(struct node** qhead, struct node** qtail, int adj_mat[vert][vert], int i)
{
    visited[i] = 1;
    enqueue(qhead, qtail, i);
    printf("%d ", i);

    while((*qtail)!= NULL)
    {
        int u = dequeue(qhead, qtail);
        for(int j = 0; j < vert; j++)
        {
            if((visited[j] == 0) && (adj_mat[u][j] == 1))
            {
                visited[j] = 1;
                printf("%d ", j);
                enqueue(qhead, qtail, j);
            }
        }
    }
    printf("\n");
}



int main(int argc, char const *argv[])
{

    struct node* qhead = NULL;
    struct node* qtail = NULL;

    scanf("%d%d", &vert, &edge);
    int adj_mat[vert][vert];
    adjacency_mat(adj_mat);
    printMat(vert, adj_mat);
    /*for (int i = 0; i < vert; i++)
    {
        if(visited[i] != 1)
        {
            DFS(adj_mat, i);
            printf("%d ", dfs_ctr);
            dfs_ctr = 0;
        }
    }*/
    
    BFS(&qhead, &qtail, adj_mat, 2);

    return 0;
}
