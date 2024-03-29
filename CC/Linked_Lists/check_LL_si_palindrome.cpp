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

struct ListNode* reverse_list(struct ListNode* A){
    struct ListNode* iter = A;
    struct ListNode* prev = NULL;
    struct ListNode* next;

    while(iter != NULL)
    {
        next = iter->next;
        iter->next = prev;
        prev = iter;
        iter = next;
    }
    return prev;
}

int check_palindrome(struct ListNode* A)
{
    struct ListNode* fast = A;
    struct ListNode* slow = A;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverse_list(slow);
    

    struct ListNode* iter = A;
    while(slow != NULL)
    {
        if(slow->val != iter->val)
            return 0;
        iter = iter->next;
        slow = slow->next;
    }
    return 1;
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
    __insert_front(&A, 5);
    __insert_front(&A, 4);
    __insert_front(&A, 3);
    __insert_front(&A, 2);
    __insert_front(&A, 1);
    print_list(A);
    cout<<check_palindrome(A);
    return 0;
}