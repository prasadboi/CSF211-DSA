#include <stdio.h>
#include <stdlib.h>
struct Node {
    int index;
    int Bx;
    int By;
    int N;
    struct Node* next;
};
void push(struct Node** head_ref, int new_data,int Bx,int By)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* 2. put in the data  */
    new_node->index = new_data;
    new_node->Bx = Bx;
    new_node->By = By;
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}
struct Node* SortedMerge(struct Node* a, struct Node* b);
void FrontBackSplit(struct Node* source,
                    struct Node** frontRef, struct Node** backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct Node** headRef)
{
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->N < b->N) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else if(a->N > b->N){
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    else if(a->N == b->N){
        if(a->index < b->index){
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else{
            result = b;
            result->next = SortedMerge(a, b->next);
        }
    }
    return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(struct Node* source,
                    struct Node** frontRef, struct Node** backRef)
{
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}




int main() {
    int N;
    int C;
    int D;
    int k;

    scanf("%d",&N);
    scanf("%d",&C);
    scanf("%d",&D);
    scanf("%d",&k);
    int Bx[C];
    int By[D];
    struct Node* head = NULL;
    for(int i = 0;i<C;i++){
        Bx[i] = 0;
    }
    for(int i = 0;i<D;i++){
        By[i] = 0;
    }
    for(int i = 0;i<N;i++){
        int x;
        int y;
        float a;
        float b;
        scanf("%f",&a);
        scanf("%f",&b);
        x = (int)a;
        y = (int)b;
        Bx[x]++;
        By[y]++;
        push(&head,i,x,y);
    }
    struct Node* temp = head;
    while (temp!=NULL){
        temp->N = Bx[temp->Bx]*By[temp->By];
        temp = temp->next;
    }
    MergeSort(&head);
    for(int i = 0;i<k;i++){
        printf("%d ",head->index);
        head = head->next;
    }
    return 0;
}