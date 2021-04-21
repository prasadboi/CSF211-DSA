#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0
#define N 100000

ll num_nodes, X, Y, start, end, visited[N], x_node = 1, y_node = 1, count, legal_count;
// node
struct node
{
    int value;
    struct node *next;
};
// creating struct node pointer vars for the adj mat operations
struct node *iter[N];
struct node *head_ptr[N];

// function declarations
struct node *new_node(int);
void DFS(int, int);
// main
int main(int argc, char const *argv[])
{

    // scanningg for values
    scanf("%lld%lld%lld", &num_nodes, &X, &Y);

    // creating the adjacency matrix
    for (int i = 0; i < num_nodes - 1; i++)
    {
        scanf("%lld%lld", &start, &end);

        struct node *temp = new_node(end);
        if (head_ptr[start] == NULL)
            head_ptr[start] = temp, iter[start] = head_ptr[start];
        else
            iter[start]->next = temp;
        iter[start] = temp;
        temp = new_node(start);
        if (head_ptr[end] == NULL)
            head_ptr[end] = temp, iter[end] = head_ptr[end];
        else
            iter[end]->next = temp;
        iter[end] = temp;
    }

    //---------------------------------------------------------------------------------------------------------------------------------------------------------------
    iter[X] = head_ptr[X];
    while (iter[X])
    {
        count = 0;
        DFS(iter[X]->value, X);
        if (!visited[Y])
            x_node += count;
        else
            visited[Y] = 0;
        iter[X] = iter[X]->next;
    }

    // initialize the visited array to 0s
    for (int i = 0; i <= num_nodes; i++)
        visited[i] = 0;

    iter[Y] = head_ptr[Y];
    while (iter[Y])
    {
        count = 0;
        DFS(iter[Y]->value, Y);
        if (!visited[X])
            y_node += count;
        else
            visited[X] = 0;
        iter[Y] = iter[Y]->next;
    }
    legal_count = num_nodes * (num_nodes - 1) - (x_node * y_node);
    printf("%lld", legal_count);
    // -----------------------------------------------------------------------------------------------------------------------------------------------------------------

    return 0;
}

// function to create a node
struct node *new_node(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->value = x;
    temp->next = NULL;
    return temp;
}

// depth first search
void DFS(int i, int P)
{
    visited[i] = 1, count++;
    iter[i] = head_ptr[i];
    while (iter[i] != NULL)
    {
        if (!visited[iter[i]->value] && iter[i]->value != P)
            DFS(iter[i]->value, P);
        iter[i] = iter[i]->next;
    }
}
