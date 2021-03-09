#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void calcMinMax_andTheirFreq(int A[], int n, int* val,int* val0,  int* freq, int* freq0)
{
    *val = A[0];
    *val0 = A[0];
    *freq = 1;
    *freq0 =  1;
    for (int i = 1; i < n; i++)
    {
        if (A[i] < *val)
        {
            *val = A[i];
            *freq = 1;
        }
        else if(A[i] == *val)
        {
            (*freq)++;
        }
        else if(A[i] == *val0)
        {
            (*freq0)++;
        }
        else if(A[i] > *val0)
        {
            *val0 = A[i];
            (*freq0) = 1;
        }
    }

    //printf("min : %d , minFreq : %d, max : %d, maxFreq : %d\n", *val, *freq, *val0, *freq0);
}


int main(int argc, char const *argv[])
{
    int n, max, maxFreq, min, minFreq;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        //printf("%d ", A[i]);
    }

    calcMinMax_andTheirFreq(A, n, &min, &max, &minFreq, &maxFreq);
    printf("%d", (max - min));
    printf(" %d", maxFreq*minFreq);

    return 0;
}
