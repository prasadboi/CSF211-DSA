#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    long int N, M;
    scanf("%d%d", &N, &M);
    long int A[N];
    for (long int i = 0; i < N; i++)
    {
        scanf("%ld", &A[i]);
    }

    long int B[M], G[M];
    for (long int i = 0; i < M; i++)
    {
        scanf("%ld%ld", &B[i], &G[i]);
    }

    for (long int i = 0; i < N; i++)
    {
        long int stolenMoney = 0;
        for (long int j = 0; j < M; j++)
        {
            if(A[i] >= B[j])
            {
                stolenMoney += G[j];
            }
        }
        printf("%d ", stolenMoney);
        
    }
    
    

    
    return 0;
}
