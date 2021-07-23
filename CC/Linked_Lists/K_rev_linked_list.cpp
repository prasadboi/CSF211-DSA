#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Linked List
struct ListNode {
    int val;
    struct ListNode *next;
};

// create a ListNode 
struct ListNode* create_node(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// insert into a linked list at front
void __insert_front(struct ListNode** A, int val)
{
    cout<<"inserting at front of list"<<endl;
    if(A == NULL){
        struct ListNode* newNode = create_node(val);
        *A = newNode;
        return;
    }  

    struct ListNode* newNode = create_node(val);
    newNode->next = (*A);
    (*A) = newNode;
    return;
}

// deleting a node from the linked list
int __delete(struct ListNode* x, struct ListNode* prev)
{
    if(x == NULL) return -1;

    prev->next = x->next;
    int retval = x->val;
    free(x);
    return retval;
}

void print_list(struct ListNode* A)
{
    cout<<"printing the list: \n";
    struct ListNode* iter = A;
    while(iter != NULL)
    {
        cout<<iter->val<<" ";
        iter = iter->next;
    }
    cout<<endl;
}

int list_length(struct ListNode* A)
{
    struct ListNode* iter = A;
    int ctr =0 ;
    while(iter != NULL)
    {
        ctr++;
        iter = iter->next;
    }
    return ctr;
}
struct ListNode* k_reversed_list_iterative(struct ListNode* A, int B)
{
    if(B == 1)
        return A;
    
    int c = 1;
    ListNode *temp = A, *prev = A, *curr = A->next, *next, *head = NULL, *temp2 = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
        if(c % B == 0){

            // for dealing with the changing head in the first block only
            head = !head ? prev : head; 
            if(temp2)
                temp2->next = prev;
            temp2 = temp;
            temp = curr;
        }
    }
    
    temp2->next = NULL;
    
    return head;

}

struct ListNode* k_reversed_list_recursive(struct ListNode* A, int B)
{
    if(A == NULL)
    {
        return A;
    }

    ListNode* prev = NULL;
    ListNode* iter = A;
    ListNode* real_next = NULL;

    int ctr = 0;

    while(iter != NULL && ctr < B)
    {
        ctr++;
        real_next = iter->next;
        iter->next = prev;
        prev = iter;
        iter = real_next;
    }
    // A becomes the tail of the ith block and 
    // prev of the i+1 th block is the head of that block. 
    // therefore a->next = prev of the next block
    A->next = k_reversed_list_recursive(iter, B);
    return prev;
}

int main(int argc, char const *argv[])
{
    struct ListNode* A = NULL;
    struct ListNode* Astar = NULL;
    __insert_front(&A, 1);
    __insert_front(&A, 2);
    __insert_front(&A, 3);
    __insert_front(&A, 4);
    __insert_front(&A, 5);
    __insert_front(&A, 6);
    __insert_front(&A, 7);
    __insert_front(&A, 8);
    __insert_front(&A, 9);
    __insert_front(&A, 10);
    print_list(A);
    A = k_reversed_list_iterative(A, 2);
    Astar = k_reversed_list_recursive(A, 2);
    print_list(A);
    print_list(Astar);
    return 0;
}
