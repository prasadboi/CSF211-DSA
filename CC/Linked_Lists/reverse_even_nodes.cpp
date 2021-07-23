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
    cout<<"inserting at front of list val : "<<val<<endl;
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

struct ListNode* __reverse_even_nodes(struct ListNode* A){
    cout<<"reversing even nodes..."<<endl;
    int ctr = 1;
    ListNode *i = A, *temp = NULL, *next = NULL;

    vector<int> rev_even;

    while(i != NULL)
    {
        if(i->next != NULL)
        {temp = i->next;
        rev_even.insert(rev_even.begin(), temp->val);
        i->next = i->next->next;
        free(temp);}
        i = i->next;
    }

    __print_list(A);
    int k;
    for(k = 0; k < rev_even.size(); k++)
    {
        cout<<" "<<rev_even[k];
    }
    cout<<endl;

    k = 0;
    i = A;
    while(k < rev_even.size() && i != NULL)
    {
        temp = __create_node(rev_even[k]);
        next = i->next;
        temp->next = next;
        i->next = temp;
        i = next;
        k++;
    }
    return A;
}
int main(int argc, char const *argv[])
{
    struct ListNode *A = NULL, *temp = NULL, *x = NULL;
    x = __insert_front(A, 3);
    A = x;
    A = __insert_front(A, 2);
    A = __insert_front(A, 1);
    /*A = __insert_front(A, 4);
    A = __insert_front(A, 5);
    A = __insert_front(A, 6);
    A = __insert_front(A, 7);
    A = __insert_front(A, 8);*/
    //A = x;
    // driver calls
    A = __reverse_even_nodes(A);
    __print_list(A);


    return 0;
}