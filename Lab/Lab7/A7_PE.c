#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ll long long int
#define TRUE 1
#define FALSE 0
#define BOOL int

struct node
{
    ll val;
    struct node* next;
    // struct node* prev;
};


// function to append to a linked list

void append(struct node** head, ll num)
{
    //printf("appending : %d\n", num);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = num;
    newNode->next = NULL;

    if((*head) == NULL)
    {
        // newNode->prev = NULL;
        (*head) = newNode;
    }
    else
    {
        struct node* last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        // newNode->prev = last;
    }
}

// function to print a linked list
void printLL(struct node** head)
{
    struct node* iter = *head;
    while (iter != NULL)
    {
        printf("%lld || ", iter->val);
        iter = iter->next;
    }
    printf("\n");
}

//function to delete the node which contains the specified value
void delete(struct node** head_ref, ll key){
    struct node* temp = *head_ref;
    struct node* prev = NULL;

    while(temp != NULL){
        if(temp->val == key && prev != NULL){
            prev->next = temp->next;
            break;
        }
        else if(temp->val == key && prev == NULL){
            temp = temp->next;
            (*head_ref) = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

int single_query(ll val1, ll val2)
{
    while((val1 != 0)|| (val2 != 0))
    {
        //printf("val1 : %d val2 : %d\n", val1, val2);
        if(val1 && val2)
        {
            if((val1%10)%2 != (val2%10)%2)
            {
                //printf("NOPE\n");
                return FALSE;
            }
        }
        else
        {
            if((val1 % 2 != 0)||(val2 % 2 != 0))
            {
                //printf("NOPE\n");
                return FALSE;
            }
        }
        val1 = val1/10;
        val2 = val2/10;
    }
    //printf("YUP\n");
    return TRUE;
}

int query(struct node** head, ll key)
{
    struct node* iter = *head;
    ll count = 0;
    while(iter != NULL)
    {
        if(single_query(iter->val, key))    
            count++;
        iter = iter->next;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    struct node* head = NULL;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char str[30];
        ll x;
        scanf("%s", str);
        if(strcmp(str, "add") == 0)
        {
            scanf("%lld", &x);
            append(&head, x);
        }
        else if(strcmp(str, "delete") == 0)
        {
            scanf("%lld", &x);
            delete(&head, x);
        }
        else if(strcmp(str, "query") == 0)
        {
            scanf("%lld", &x);
            printf("%lld\n",query(&head, x));
        }
        //printLL(&head);
    }

    //printf("%d",single_query(133, 222222133));

    return 0;
}


