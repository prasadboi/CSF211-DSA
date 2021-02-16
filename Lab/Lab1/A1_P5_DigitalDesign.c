#include <stdio.h>
#include <stdlib.h>

struct bit
{
    char bitVal;
    struct bit *next;
    struct bit *prev;
};

// appending to doubly linked list
void append(struct bit** head, char num)
{
    
    struct bit* newNode = (struct bit*)malloc(sizeof(struct bit));
    newNode->bitVal = num;
    newNode->next = NULL;
    struct bit* last = *head;
    
    if((*head) == NULL)
    {
        newNode->prev = NULL;
        (*head) = newNode;
    }
    else
    {
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
}

// printing bitString
void printBitString(struct bit** head)
{
    struct bit* last = *head;
    int i = 0; 
    while (last != NULL)
    {
        printf("%c",last->bitVal);
        last = last->next;
        //printf("%d:%d ", i, last->num);
        i++;
    }
}

void LeftRotate(struct bit** head, struct bit** last)
{
    struct bit *temp = *head;
    (temp->next)->prev = NULL;
    *head = temp->next;
    (*last)->next = temp;
    temp->prev = *last;
    temp->next = NULL;
    (*last) = temp;
}
void RightRotate(struct bit** head, struct bit** last)
{
    struct bit *temp = *last;
    temp->prev->next = NULL;
    *last = temp->prev;
    temp->prev = NULL;
    temp->next = *head;
    *head = temp;
}
void LeftShift(struct bit** head, struct bit** last)
{
    append(head, '0');
    (*last) = (*last)->next;
    (*head)->next->prev = NULL;
    *head = (*head)->next;
}

void RightShift(struct bit** head, struct bit** last)
{
    struct bit* newNode = (struct bit*)malloc(sizeof(struct bit));
    newNode->bitVal = '0';
    newNode->prev = NULL;
    newNode->next = (*head);
    newNode->next->prev = newNode;
    (*head) = newNode;
    (*last)->prev->next = NULL;
    (*last) = (*last)->prev;
}

void addOne(struct bit** last)
{
    struct bit* ptr = *last;
    while (ptr->prev != NULL && ptr->bitVal == '1')
    {
        ptr->bitVal = '0';
        ptr = ptr->prev;
    }
    if(ptr->bitVal == '0')
        ptr->bitVal = '1';
    else
        ptr->bitVal = '0';
}

void subtractOne(struct bit** last)
{
    struct bit* ptr = *last;
    while (ptr->prev != NULL && ptr->bitVal == '0')
    {
        ptr->bitVal = '1';
        ptr = ptr->prev;
    }
    if(ptr->bitVal == '1')
        ptr->bitVal = '0';
    else
        ptr->bitVal = '1';
}




int main(int argc, char const *argv[])
{
    struct bit* head = NULL;
    struct bit* last = NULL;
    char x, arg[3];
    int len = 0, args_num = 0;
    
    scanf("%c", &x);
    while (x != '\n')
    {
        append(&head, x);
        scanf("%c", &x);
    }
    last = head;
    while(last->next != NULL)
    {
        last = last->next;
    }

    scanf("%d", &args_num);
    for (int i = 0; i < args_num; i++)
    {
        scanf("%s", arg);
        switch (arg[0])
        {
        case 'L':
            if (arg[1] == 'R')
            {
                LeftRotate(&head, &last);
            }
            else if(arg[1] == 'S')
            {
                LeftShift(&head, &last);
            }
            break;

        case 'R':
            if (arg[1] == 'R')
            {
                RightRotate(&head, &last);
            }
            else if(arg[1] == 'S')
            {
                RightShift(&head, &last);
            }

        case 'I' : 
            if(arg[1] == 'N' && arg[2] == 'C')
            {
                addOne(&last);
            }

        case 'D': 
            if (arg[1] == 'E' && arg[2] == 'C')
            {
                subtractOne(&last);
            }
        default:
            break;
        }
    }
    printBitString(&head);printf("\n");
    return 0;
}

