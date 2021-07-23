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

/*i ← 1
while i < length(A)
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
    end while
    i ← i + 1
end while*/


struct ListNode* __list_insertion_sort(struct ListNode* A)
{
    if(A == NULL || A->next == NULL)
        return A;

    ListNode* i = A;

    while(i!= NULL)
    {
        ListNode* next = i->next;
        ListNode* j = A;
        ListNode* j_prev = A;

        while(j!= next)
        {
            // if j->val is greater than i->val then swap the two and make necessary link changes.
            if(j->val > i->val)
            {
                if(j == A)
                {
                    A = i;
                }
                else
                {
                    j_prev->next = i;
                }

                // iterate through the list till you reach the original position of i
                while(j->next != i)
                {
                    j = j->next;
                }
                j->next = next;
                // i has been unlinked now (in abv line)

                // now we maintain j and j_prev relations
                j_prev = j;
                j = j->next;
            }
            i = next;
        }
    }
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
    
    // enter your driver calls here.
    A = __list_insertion_sort(A);
    print_list(A);
    return 0;
}