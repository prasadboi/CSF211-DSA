#include <stdio.h>
#include <math.h>

void inputArr(long int arr[], long int N)
{
    for (long int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    
}

void countGoodPairs(long int x[], long int y[], int n, long int k1, long int k2)
{
    int ctr = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if((x[i] + x[j] + k1) > (y[i] + y[j] + k2))
                {
                    //printf("%d ,%d\n", j+1, i+1);
                    ctr++;
                }
            }
        }
    printf("%d", ctr);
}

int main(int argc, char const *argv[])
{
    int N;
    long int k_1, k_2;
    scanf("%d%ld%ld", &N, &k_1, &k_2);
    long int X[N], Y[N];
    inputArr(X, N);
    inputArr(Y, N);
    countGoodPairs(X, Y, N, k_1, k_2);

    return 0;
}
