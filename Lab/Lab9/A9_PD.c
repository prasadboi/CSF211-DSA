#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0
//#define INT_MAX 32001

// struct to store details of the coordinates (x and y) of Zoro
struct node 
{
    ll x;
    ll y;
};

struct node* createNode(ll x_pos, ll y_pos)
{
    struct node*  newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->x = x_pos;
    newNode->y = y_pos;
}

// movement functions
void UP(struct node* pos)
{
    pos->y++;
}
void DOWN(struct node* pos)
{
    pos->y--;
}
void LEFT(struct node* pos)
{
    pos->x--;
}
void RIGHT(struct node* pos)
{
    pos->x++;
}


void MOVE(struct node* final_pos, char moves[], ll length)
{
    //printf("moves = %s, length = %lld\n", moves, length);
    for (ll i = 0; i < length; i++)
    {
        char command;
        command = moves[i];
        //printf("char : %c ", command);
        // performing operations
        switch (command)
        {
        case 'U':
            UP(final_pos);
            break;
        case 'D':
            DOWN(final_pos);
            break;
        case 'R':
            RIGHT(final_pos);
            break;
        case 'L':
            LEFT(final_pos);
            break;
        default:
            printf("wrong command bruh\n");
            break;
        }
        //printf("\n");
    } 
}

ll displacement(struct node* ini, char moves[], ll length)
{
    struct node* fin = createNode(ini->x, ini->y);
    MOVE(fin, moves, length);
    ll disp_sq = (((ini->x - fin->x)*(ini->x - fin->x)) + ((ini->y - fin->y)*(ini->y - fin->y)));
    free(fin);
    return disp_sq;
}

void shortest_useless_loop(char moves[], ll length, ll positional_info[2])
{
    ll min_count = INT_MAX;
    struct node* pos = createNode(0, 0);
    for (ll i = 0; i < length-1; i++)
    {
        struct node* ini = pos;
        ll disp_sq = 0;
        ll count = 0;
        for (ll j = i+1; j < length; j++)
        {
            printf("j is equal to  : %lld || ", j);
            printf("moves : %s  || ", moves + i);
            printf("length of moves is : %lld || ", j-i + 1);
            disp_sq = displacement(ini, (moves + i), j-i + 1);
            count++;
            printf("displacement : %lld\n", disp_sq);
            if(disp_sq == 0)
            {
                printf("disp_sq = 0!!!, count : %lld \n", count);
                if(min_count > count)
                {
                    min_count = count;
                    positional_info[0] = i+1;
                    positional_info[1] = j+1;
                    printf("new min count = %lld\n", min_count);
                }
            }
        }
        //free(ini);
    }
    
}

int main(int argc, char const *argv[])
{
    struct node* zoro_pos = createNode(0, 0);
    //MOVE(zoro_pos, "LURDLLLRRD", 10);
    //printf("%lld %lld", zoro_pos->x, zoro_pos->y);
    ll index_info[2] = {0};
    //printf("disp_sq = %lld\n", displacement(zoro_pos, "LURDLLLRR", 9));
    shortest_useless_loop("LURDLLLRRD", 10, index_info);
    printf("index info : %lld %lld\n", index_info[0], index_info[1]);
    return 0;
}
