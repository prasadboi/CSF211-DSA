#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void matchUp(int* A, int* B, int alpha)
{
    if(*A < *B)
    {
        *B = abs(*B - (alpha*(*B - *A)));
        *A = -1;
    }
    else if(*A == *B)
    {
        *A = -1;
        *B = - 1;
    }
    else
    {
        *A = abs(*A - (alpha * (*A - *B)));
        *B = -1;
    }
}
/*void print_arr(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}*/

void Round(int candidates[], int N, int alpha, int beta)
{
    int ctr = 0;
    for (int i = 0; i < N; )
    {
        int flag = 0;
        //ctr = 0;
        if(candidates[i] != -1)
        {
            ctr++;
            for (int j = i+1; j < N; j++)
            {
                if(candidates[j] != -1)
                {
                    //printf("%d %d\n", i, j);
                    matchUp(&candidates[i], &candidates[j], alpha);
                    i = j+1;
                    flag = 1;
                    break;
                }
            }
            if( flag == 0)
            {
                //printf("%d\n", i);
                candidates[i] += beta;
            }
        }
        if(flag == 0)
            i++;
        
    }

    if(ctr > 1)
    {
        //printf("next Round !!!!\n");
        //print_arr(candidates, N);
        Round(candidates, N, alpha, beta);
    }
    else if(ctr == 1)
    {
        int f = 0;
        for (int i = 0; i < N; i++)
        {
            if(candidates[i] != -1)
            {
                printf("%d %d\n",i+1, candidates[i]);
                f = 1;
            }
        }
        if(f == 0)
            printf("-1 -1\n");
    }
    
}


int main(int argc, char const *argv[])
{
    int N, alpha, beta;
    scanf("%d%d%d", &N, &alpha, &beta);
    int robo_candidates[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &robo_candidates[i]);
    }
    Round(robo_candidates, N, alpha, beta);
    //Round(robo_candidates, N, alpha);
    //print_arr(robo_candidates, N);
    
    return 0;
}
