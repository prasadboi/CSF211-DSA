#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Partition(int arr[], int P, int R)
{
    int temp;
    int X = arr[R];
    int i = P - 1;
    for (int j = P; j <= R-1; j++)
    {
        if(arr[j] <= X)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i + 1] = arr[R];
    arr[R] = temp;

    return (i+1);
}

void quickSort(int arr[], int P, int R)
{
    if(P < R)
    {
        int Q = Partition(arr, P, R);
        quickSort(arr, P, Q-1);
        quickSort(arr, Q+1, R);
    }
}

/*void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}*/

int main(int argc, char const *argv[])
{
    int M, N;
    scanf("%d%d", &M, &N);

    int m[M];
    int n[N];

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &m[i]);
    }
    //printArray(m, M);
    //printf("Entered m successfully \n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n[i]);
    }
    //printArray(n, N);

    quickSort(m, 0, M-1);
    //printArray(m, M);

    for (int i = 0; i < N; i++)
    {
        int ctr = 0;
        for (int j = 0; j < M; j++)
        {
            if(m[j] > n[i])
                break;
            ctr++;
        }
        printf("%d ", ctr);
        ctr = 0;
    }
    
    
    
    return 0;
}
