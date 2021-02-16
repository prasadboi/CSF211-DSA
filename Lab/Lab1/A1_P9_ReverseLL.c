#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

void append(int Num)
{
    
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->num = Num;
    newNode->next = NULL;
    
    if((head) == NULL)
    {
        //newNode->prev = NULL;
        (head) = newNode;
    }
    else
    {
        struct node* last = head;
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        //newNode->prev = last;
    }
}

void flipList()
{
    //printf("Calling flipList\n");
    struct node* ptr = head;
    struct node* prev = NULL;
    struct node* real_next = NULL ;
    while (ptr != NULL)
    {
        real_next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = real_next; 

    }
    head = prev;
    
}

void printList()
{
    struct node* last = head;
    int i = 0; 
    while (last != NULL)
    {
        printf("%d ",last->num);
        last = last->next;
        //printf("%d:%d ", i, last->num);
        i++;
    }
}

int main(int argc, char const *argv[])
{
    int len = 0, flag = 0, num;
    scanf("%d", &len);
    for (int i = 0; i < len ; i++) {
        scanf("%d", &num);
	    append(num);
	}
    //printList();
    //printf("\n%d", head->num);
    //printf("\n%d", (*last).num);
    flipList();
    printList();
    //printf("\n%d", head->num);
    //printf("\n%d", last->num);
    

    return 0;
}
