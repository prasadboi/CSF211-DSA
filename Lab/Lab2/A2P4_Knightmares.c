#include <stdio.h>
//#include <math.h>

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d%d", &N, &M);
    long int Knightmare[N];
    long int powerUps[M];

    for(int i = 0; i < N; i++){
        scanf("%ld", &Knightmare[i]);
    }
    for(int i = 0; i < M; i++){
        scanf("%ld", &powerUps[i]);
    }

    for (int i = 0; i < (N-M)+1; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Knightmare[i+j] *= powerUps[j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        printf("%ld ", Knightmare[i]);
    }
    
    
    return 0;
}
