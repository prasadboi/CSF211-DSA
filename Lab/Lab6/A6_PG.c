#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;

    struct Node *next;
};
int hammingDistance(int node1, int node2)
{
    int alpha = node1 ^ node2;
    int bits = 0;

    while (alpha > 0) {
        bits += alpha & 1;
        alpha >>= 1;
    }

    return bits;
}
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

unsigned int Log2n(unsigned int n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
}

int power(int a, unsigned int b)
{
    if (b == 0)
        return 1;
    else if (b%2 == 0)
        return power(a, b/2)*power(a, b/2);
    else
        return a*power(a, b/2)*power(a, b/2);
}
void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}
int main() {
    int N;
    int a;
    int b;
    scanf("%d",&N);
    scanf("%d",&a);
    scanf("%d",&b);
    int AB[N];

    int ind_a = -1;
    int ind_b = -1;
    for(int i = 0;i<N;i++){
        scanf("%d",&AB[i]);

    }
    for(int i = 0;i<N;i++){
        if(AB[i] == a){
            ind_a = i;
        }
        if(AB[i] == b){
            ind_b = i;
        }
    }
    //printf("%d %d ",ind_a,ind_b);
    if(ind_a == -1 || ind_b == -1){
        printf("-1");
        return 0;
    }
    if(ind_a == 0 || ind_b == 0){
        printf("0");
        return 0;
    }
    struct Node* A = NULL;
    struct Node* B = NULL;
    struct Node* C = NULL;
    //printf("Over ");
    int k = Log2n(N+1)-1;
    int m = power(2,k);
    for(int i = N-1;i>=N-m;i--) {
        if (AB[i] != -1) {
            int p = i;
            do {
                    //printf("%d\n",p);
                if (p == ind_a) {
                    //printf("here");
                    push(&A, AB[i]);
                } else if (p == ind_b) {

                    push(&B, AB[i]);
                }
                if (p % 2 == 0) {
                    p = (p - 2) / 2;
                } else {
                    p = (p - 1) / 2;
                }
            } while (p != 0);
        }

    }

    for(int i = 0;i<m-1;i++){
        if(AB[2*i+1] == -1 && AB[2*i+2] == -1 && AB[i]!= -1){
            int p = i;
            do {

                if (p == ind_a) {
                    push(&A, AB[i]);
                } else if (p == ind_b) {
                    push(&B, AB[i]);
                }
                if (p % 2 == 0) {
                    p = (p - 2) / 2;
                } else {
                    p = (p - 1) / 2;
                }
            } while (p != 0);
        }
    }


    int min1 = hammingDistance(A->data, B->data);
   //printf(A->data);
   struct Node* temp1 = B;
    while (A!=NULL){
        B = temp1;
        while(B!=NULL){
            //push(&C,hammingDistance(A->data,B->data));
            int t = hammingDistance(A->data, B->data);
            if(t < min1)
                min1 = t;
            B = B->next;
        }
        A = A->next;
    }

    /*int min = C->data;
    while (C!=NULL){
        if(C->data < min){
            min = C->data;
        }
        C = C->next;
    }*/

    printf("%d",min1);
    return 0;
}
