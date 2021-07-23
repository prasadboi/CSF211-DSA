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
    cout<<"printing the list \n";
    struct ListNode* iter = A;
    while(iter != NULL)
    {
        cout<<iter->val<<" ";
        iter = iter->next;
    }
    cout<<endl;
}

void __bin_list_sort(struct ListNode** A)
{
    if(*A == NULL) return;
    struct ListNode* iter = (*A)->next;
    struct ListNode* trail = (*A);
    while(iter != NULL)
    {
        if(iter->val == 0)
        {
           trail->next = iter->next;
           iter->next = *A;
           (*A) = iter;
           iter = trail->next;
        }
        else
        {
            iter = iter->next;
            trail = trail->next;
        }
    }
}

// main
int main(int argc, char const *argv[])
{
    struct ListNode* A = NULL;
    __insert_front(&A, 0);
    __insert_front(&A, 1);
    __insert_front(&A, 0);
    __insert_front(&A, 0);
    __insert_front(&A, 0);
    __insert_front(&A, 1);
    __insert_front(&A, 1);
    __insert_front(&A, 1);
    cout<<"A val = "<<A->val<<endl;
    print_list(A);

    __bin_list_sort(&A);

    print_list(A);


    return 0;
}
