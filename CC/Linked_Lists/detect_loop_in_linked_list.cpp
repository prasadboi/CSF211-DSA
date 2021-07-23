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
    ////cout<<"checkpoint 1"<<endl;
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

struct ListNode* __search_list_prev(struct ListNode* A, int key)
{
    struct ListNode* iter = A;
    if(iter->val == key) return NULL;
    while(iter->next != NULL)
    {
        if(iter->next->val == key)
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


struct ListNode* __Detect_cycles_v1(struct ListNode* A)
{
    ListNode *sentinel_node = __create_node(-1), *i = A, *temp;
    int flag = 0;
    while(i != NULL){
        if(i->next == sentinel_node)
        {
            return i;
        }
        else
        {
            temp = i->next;
            i->next = sentinel_node;
            i = temp;
        }
    }
    return NULL;
}

// floyd's cycle detection algorithm. 
// To get starting point of cycle 
// you need to get length of the cycle 
// and then check for cycle's starting point.
struct ListNode* __Detect_cycles_v2(struct ListNode* head)
{
    if(head == NULL)
            return NULL;
        ListNode *fa = head->next, *sl = head;
        int flag = 0;
        while(fa != NULL && sl != NULL && fa->next != NULL)
        {
            if(fa == sl)
            {
                flag++;
                break;
            }
            fa = fa->next->next;
            sl = sl->next;
        }
        
        if(!flag)
            return NULL;
        // floyd detection part over
        


        // calculate the length of the cycle
        int ctr = 1;
        while(sl->next != fa)
        {
            sl = sl->next;
            ctr++;
        }
        // gap b/w the start and the end of the cycle is ctr
        sl = head;
        fa = head;
        for(int i = 0; i < ctr; i++)
        {
            fa = fa->next;
        }
        while(sl != fa)
        {
            sl = sl->next;
            fa = fa->next;
        }
        return sl;
}


int main(int argc, char const *argv[])
{
    struct ListNode *A = NULL, *temp = NULL, *x = NULL;
    x = __insert_front(A, 4);
    A = x;
    A = __insert_front(A, 2);
    A = __insert_front(A, 7);
    A = __insert_front(A, 9);
    A = __insert_front(A, 5);
    A = __insert_front(A, 4);
    A = __insert_front(A, 3);
    A = __insert_front(A, 2);
    temp = __insert_front(A, 1);
    
    x->next = temp;
    //A = x;

    
    cout<<__Detect_cycles_v1(A)->val<<endl;
    cout<<__Detect_cycles_v2(A)->val<<endl;


    return 0;
}
