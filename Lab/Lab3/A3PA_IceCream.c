#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    long int N, M, k, ctr = 0;
    scanf("%ld%ld%ld", &N, &M, &k);
    //printf("N : %d, M : %d, k : %d\n", N, M, k);
    int A[N];
    for(long int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    int S[M];
    for (long int i = 0; i < M; i++)
    {
        scanf("%d", &S[i]);
    }

    for (long int i = 0; i < N;i++)
    {
        for(long int j =0; j < M; j++)
        {
            if((S[j] != -1) && (abs(A[i] - S[j]) <= k))
            {
                S[j] = -1;
                ctr++;
                break;
            }
        }
        //printf("i : %d, ctr : %d\n", i, ctr);
    }
    //printArr(visited, M);

    printf("%d", ctr);
    
    
    return 0;
}