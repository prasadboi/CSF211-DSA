#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    int mod;
    struct Node* next;
};
void push(struct Node** head_ref, int new_data,int k)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->mod = new_data%k;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
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
    if (a->mod < b->mod) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else if(a->mod > b->mod){
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    else if(a->mod == b->mod){
        if(a->data <= b->data){
            result = a;
            result->next = SortedMerge(a->next,b);
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
    int k;
    scanf("%d",&N);
    scanf("%d",&k);
    struct Node* a = NULL;
    for(int i = 0;i<N;i++){
        int b;
        scanf("%d",&b);
        push(&a,b,k);
    }
    MergeSort(&a);
    for(int i = 0;i<N-1;i++){
        printf("%d ",a->data);
        a = a->next;
    }
    printf("%d", a->data);


    return 0;
}