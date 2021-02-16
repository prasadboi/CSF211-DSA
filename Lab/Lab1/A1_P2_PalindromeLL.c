#include <stdio.h>
#include <stdlib.h>

struct CHAR 
{
  char c;
  struct CHAR* next;
  struct CHAR* prev;  
};


void append(struct CHAR** head, char new_ch)
{
    
    struct CHAR* newChar = (struct CHAR*)malloc(sizeof(struct CHAR));
    newChar->c = new_ch;
    newChar->next = NULL;
    struct CHAR* last = *head;
    
    if((*head) == NULL)
    {
        newChar->prev = NULL;
        (*head) = newChar;
    }
    else
    {
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = newChar;
        newChar->prev = last;
    }
}



int main(void) 
{
    struct CHAR* head = NULL;
    struct CHAR* last = NULL;
    char c;
	int len = 0, flag = 0;
	scanf("%d", &len);

	for (int i = 0; i < len +1  ; i++) {
        scanf("%c", &c);
	    append(&head, c);
	}

    // printList(head);
    
    last = head;
    while(last->next != NULL)
        {
            last = last->next;
        }
    struct CHAR* frontNode;
    frontNode = head->next;
    struct CHAR* backNode;
    backNode = last;

    while (frontNode != last)
    {
        if(frontNode->c != backNode->c)
        {
            flag = 1;
        }
        frontNode = frontNode->next;
        backNode = backNode->prev;
    }
    

    if(flag == 1){
        printf("NOT A PALINDROME");
    }
    else
    {
        printf("PALINDROME");
    }
    


	return 0;
}

