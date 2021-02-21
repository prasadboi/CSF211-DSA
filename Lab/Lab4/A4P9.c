#include <stdio.h>

long permutations(int n);

int main(){
    int N, x, pos;
    scanf("%d%d%d", &N, &x, &pos);
    
    long output  = permutations(N-1);
    printf("%ld", output);
    return 0;
}

long permutations(int n){
    long fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;
}