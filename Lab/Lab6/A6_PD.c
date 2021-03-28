#include <stdio.h>

int main() {
    int N;
    int k;
    int X;
    scanf("%d",&N);
    scanf("%d",&k);
    scanf("%d",&X);
    int A[N];
    int B[k];
    int C[k];
    for(int i = 0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i = 0;i<k;i++){
        scanf("%d",&B[i]);
    }
    for(int i = 0;i<k;i++){
        C[i] = A[B[i]];
        for(int j = i+1;j<k;){
            if(B[j]-B[i]<=X){
                C[i] = C[i] + A[B[j]];
             j++;
            }
            else{
                break;
            }
        }
    }
    int without = 0;
    int max = 0;
    for(int i = 0;i<N;i++){
        without = without + A[i];
    }
    for(int i = 0;i<k;i++){
        without = without - A[B[i]];
        if(C[i] > max){
            max = C[i];
        }
    }
    printf("%d %d",without,without+max);
    return 0;
}