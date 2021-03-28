#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int

struct node 
{
    ll val;
    struct node* next;
};

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


struct node *reverse (struct node *head, int i, int arr[])
{
    if (!head)
        return NULL;
   
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;
   
     
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < arr[i])
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
    /* next is now a pointer to (k+1)th node
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    i++;
    if (next !=  NULL)
       head->next = reverse(next,i ,arr);
 
    /* prev is new head of the input list */
    return prev;
}

int main(int argc, char const *argv[])
{
    ll n, k;
    ll x;
    int net_index = 0;
    struct node* head = NULL;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        append(&head, x);
    }
    printLL(&head);
    /*for (int i = 0; i < k; i++)
    {
        scanf("%lld", &x);
        printf("net_index = %d, final pos = %d\n", net_index, net_index + x);
        (head) = flipList(&head, x);
        net_index += x;
        printLL(&head);
    }*/
    int arr[k];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    
    head = reverse(head, 0, arr);
    printLL(&head);
    struct node* iter = head;
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        int count = 0;
        while((iter != NULL)&&(count < arr[i]))
        {
            iter->val = iter->val * arr[i];
            iter = iter->next;
            count++;
        }
    }
    printLL(&head);
    
    
    

    return 0;
}
