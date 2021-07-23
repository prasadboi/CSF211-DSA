#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Linked List
struct ListNode {
    int val;
    struct ListNode *next;
};

// create a ListNode 
struct ListNode* __create_node(int val) {
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
        struct ListNode* newNode = __create_node(val);
        A = newNode;
        return A;
    }  

    struct ListNode* newNode = __create_node(val);
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

void __print_list(struct ListNode* A)
{
    if(A == NULL) return;
    cout<<"printing the list: \n";
    struct ListNode* iter = A;
    while(iter != NULL)
    {
        cout<<iter->val<<" ";
        iter = iter->next;
    }
    cout<<endl;
}

int __list_length(struct ListNode* A)
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


struct ListNode* __reverse_list(struct ListNode* A){
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

struct ListNode* __delete_nth_node_from_end(struct ListNode* A, int N)
{
    ListNode *i = A, *j = A;
    ListNode* temp;

    for(int x = 0; x < N && j != NULL; x++)
    {
        j = j->next;
    }
    //cout<<"checkpoint1\n";
    if(j == NULL){
        A = A->next;
        cout<<"deleting first element from the list\n";
        return A;
    }
    while(j != NULL && j->next != NULL)
    {
        i = i->next;
        j = j->next;
    }
    //cout<<"checkpoint2\n";
    temp = i->next;
    if(i->next != NULL)
        i->next = i->next->next;
    else if(i->next == NULL){
        cout<<"checkpoint3\n";
        if(A == i){
            cout<<"it is null\n";
            return NULL;
        }
        else
            temp = i;
    }
    //cout<<"checkpoint4\n";
    free(temp);
    return A;
}

int main(int argc, char const *argv[])
{
    struct ListNode* A = NULL;
    /*A = __insert_front(A, 5);
    A = __insert_front(A, 4);
    A = __insert_front(A, 3);
    A = __insert_front(A, 2);*/
    A = __insert_front(A, 1);
    /*A = __insert_front(A, 5);
    A = __insert_front(A, 7);
    A = __insert_front(A, 4);
    A = __insert_front(A, 3);*/
    __print_list(A);
    
    // enter your driver calls here.
    A = __delete_nth_node_from_end(A, 1);

    // output
    __print_list(A);
    return 0;
}
