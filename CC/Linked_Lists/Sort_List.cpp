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
struct ListNode* __insert_front(struct ListNode* A, int val)
{
    cout<<"inserting at front of list"<<endl;
    //cout<<"checkpoint 1"<<endl;
    if(A == NULL){
        struct ListNode* newNode = create_node(val);
        A = newNode;
        return A;
    }  

    struct ListNode* newNode = create_node(val);
    //cout<<"checkpoint 2"<<endl;
    newNode->next = (A);
    //cout<<"checkpoint 3"<<endl;
    (A) = newNode;
    //cout<<"checkpoint 4"<<endl;
    return A;
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

struct ListNode* merge(struct ListNode* A_head, struct ListNode* B_head)
{
    struct ListNode *i = A_head, *j = B_head, *k = NULL;
    struct ListNode* head = NULL;
    while((i != NULL) && (j != NULL))
    {
        cout<<"i val, j val are : "<<i->val<<j->val<<"respectively"<<endl;
        if(i->val <= j->val)
        {
            cout<<"checkpoint 1"<<endl;
            if(head == NULL)
            {
                head = i;
                k = head;
            }
            else
            {
                k->next = i;
                k = i;
            }
            i = i->next;
        }

        else
        {
            if(head == NULL)
            {
                head = j;
                k = head;
            }
            else
            {
                k->next = j;
                k = j;
            }
            j = j->next;
        }
    }

    if(i == NULL)
    {
        k->next = j;
    }
    else if(j == NULL)
    {
        k->next = i;
    }

    
    return head;
}


struct ListNode* listSort(struct ListNode* A)
{
    int len=0;
    ListNode* x = A;
    while (x != NULL) {
        x = x->next;
        len++;
    }

    if (len <= 1) {
        return A;
    }

    x = A;
    for (int i=1; i<len/2; i++) {
        x = x->next;
    }

    ListNode* y = x->next;
    x->next = NULL;

    ListNode* left = listSort(A);
    ListNode* right = listSort(y);
    return merge(left, right);
}


//----------------------------------------------------------------------------
// Sorting a linked list in O(n log n) time using constant space complexity.


int main(int argc, char const *argv[])
{
    struct ListNode* A = NULL;
    struct ListNode* B = NULL;
    A = __insert_front(A, 4);
    A = __insert_front(A, 2);
    A = __insert_front(A, 7);
    A = __insert_front(A, 9);
    A = __insert_front(A, 5);
    A = __insert_front(A, 4);
    A = __insert_front(A, 3);
    A = __insert_front(A, 2);
    A = __insert_front(A, 1);

    B = __insert_front(B, 9);
    B = __insert_front(B, 8);
    B = __insert_front(B, 7);
    B = __insert_front(B, 6);
    B = __insert_front(B, 5);
    B = __insert_front(B, 4);
    print_list(A);
    

    ListNode* A_tail = A;
    // enter your driver calls here.
    while(A_tail->next != NULL)
    {
        A_tail = A_tail->next;
    }

    ListNode* B_tail = B;
    // enter your driver calls here.
    while(B_tail->next != NULL)
    {
        B_tail = B_tail->next;
    }

    A = listSort(A);
    
    print_list(A);
    return 0;
}