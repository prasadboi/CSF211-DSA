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

struct ListNode* __search_list(struct ListNode* A, int key)
{
    struct ListNode* iter = A;
    while(iter != NULL)
    {
        if(iter->val == key)
        {
            return iter;
        }
        iter = iter->next;
    }
    return NULL;
}

struct ListNode* __partition_list(struct ListNode* A, int B)
{
    struct ListNode* iter = A;
    struct ListNode *fh = NULL, *ft = NULL, *th = NULL, *tt = NULL;
    while(iter != NULL){
        struct ListNode* temp = iter;
        iter = iter->next;

        if(temp->val < B)
        {
            if(fh == NULL && ft == NULL)
            {
                fh = temp;
                ft = temp;
            }
            else if(ft != NULL)
            {
                ft->next = temp;
                ft = temp;
            }
            //cout<<"fh : "<<fh->val<<"  ft: "<<ft->val<<endl;
        }
        else
        {
            temp->next = NULL;
            if(th == NULL && tt == NULL)
            {
                th = temp;
                tt = temp;
            }
            else if(tt != NULL)
            {
                tt->next = temp;
                tt = temp;
            }
        }
    }
    if(fh != NULL)
        ft->next = th;
    if(fh != NULL)
        return fh;
    else 
        return th;
}

int main(int argc, char const *argv[])
{
    struct ListNode* A = NULL;
    A = __insert_front(A, 1);
    A = __insert_front(A, 2);
    A = __insert_front(A, 3);
    A = __insert_front(A, 4);
    A = __insert_front(A, 5);
    A = __insert_front(A, 6);
    A = __insert_front(A, 7);
    A = __insert_front(A, 8);
    A = __insert_front(A, 9);
    print_list(A);
    A = __partition_list(A, 5);
    print_list(A);
    return 0;
}
