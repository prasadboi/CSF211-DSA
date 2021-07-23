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

int carry = 0;
struct ListNode* add_2_rev_numbers(struct ListNode* A, struct ListNode* B)
{
    struct ListNode* result = create_node(0);
    
    if((A!=NULL) & (B == NULL))
    {
        result->val = (A->val + carry)%10;
        carry = (A->val + carry)/10;
        cout<<"carry : "<<carry<<" result : "<<result->val<<endl;
        result->next = add_2_rev_numbers(A->next, B);
    }
    else if((A == NULL) && (B!= NULL))
    {
        result->val = (B->val + carry)%10;
        carry = (B->val + carry)/10;
        cout<<"carry : "<<carry<<" result : "<<result->val<<endl;
        result->next = add_2_rev_numbers(A, B->next);
    }
    else if((A != NULL) && (B != NULL))
    {
        result->val = (A->val + carry + B->val)%10;
        carry = (A->val + carry + B->val)/10;
        cout<<"carry : "<<carry<<" result : "<<result->val<<endl;
        result->next = add_2_rev_numbers(A->next, B->next);
    }
    else
    {
        if(carry == 0)
        {
            return NULL;
        }
        result->val = carry;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    struct ListNode* A = NULL;
    struct ListNode* B = NULL;
    __insert_front(&A, 1);
    __insert_front(&A, 9);
    __insert_front(&A, 9);
    __insert_front(&B, 1);
    
    print_list(A);
    print_list(B);
    print_list(add_2_rev_numbers(A, B));
    return 0;
}
