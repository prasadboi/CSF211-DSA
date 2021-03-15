#include <Stdio.h>
#include <stdlib.h>
#include <math.h>

void copyArray(int A[], int B[], int n)
{
    for (int i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
}

int minArray(int A[], int n)
{
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        if(A[min] > A[i])
            min = i;
    }
    return min;
}

int maxArray(int A[], int n)
{
    int max = 0; // index 
    for (int i = 0; i < n; i++)
    {
        if(A[max] < A[i] && A[i] != INFINITY)
            max = i;
    }
    return max;
}

int deleteElement(int A[], int index , int n)
{
    for(int i = index; i < n-1; i++)
    {
        A[i] = A[i+1];
    }
    return n-1;
}

long int sumArray(int A[], int n)
{
    long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    return sum;
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
}

int main(int argc, char const *argv[])
{
    int N, q;
    scanf("%d%d", &N, &q);
    
    int temp[N], A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    // scanning Ki values
    int K[q];
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &K[i]);
    }
    
    //processing queries
    for (int i = 0; i < q; i++)
    {
        int k;
        int len = N;
        k = K[i];

        // creating temporary array on which operations are done
        copyArray(A, temp, N);
        for (int j = 0; j < k; j++)
        {
            //printf("j : %d\n",j);
            int max = temp[maxArray(temp, len)];
            int min = temp[minArray(temp, len)];
            int diff = max-min;
            //printf("min : %d, max : %d, diff : %d || ", min, max, diff);
            temp[minArray(temp, len)] = diff;
            len = deleteElement(temp, maxArray(temp, len), len);
            //printArray(temp, len);
        }
        printf("%ld\n", sumArray(temp, len));
    }
    
    return 0;
}
