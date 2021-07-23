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

int kth_element_from_mid(struct ListNode* A, int B)
{
    int length = list_length(A);
    struct ListNode* iter = A;
    if(B >= ((length/2) + 1))
    {
        return -1;
    }

    for(int i = 0; i < ((length/2) + 1) - B - 1; i++)
    {
        iter = iter->next;
    }
    return iter->val;
}

int kth_element_from_mid_diff_approach(struct ListNode* A, int B)
{
    struct ListNode *p = create_node(0);
    struct ListNode *sl = A, *fa = A;
    p->next = A;
    while(fa && fa->next) {
        sl = sl->next;
        fa = fa->next->next;// moves twice as fast as sl

        // smart moves ensue
        B--;
        if(B <= 0)
            p = p->next;
    }
    if(B > 0)
        return -1;
    return p->val;
}

int main(int argc, char const *argv[])
{
    struct ListNode* A = NULL;
    __insert_front(&A, 1);
    __insert_front(&A, 2);
    __insert_front(&A, 3);
    __insert_front(&A, 4);
    __insert_front(&A, 5);
    __insert_front(&A, 6);
    __insert_front(&A, 7);
    __insert_front(&A, 8);
    __insert_front(&A, 9);
    cout<<kth_element_from_mid(A, 1)<<endl;
    cout<<kth_element_from_mid_diff_approach(A, 1);
    return 0;
}
