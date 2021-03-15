#include <stdio.h>
//#include <math.h>

// create a heap having all the differences. Pop out the root k times
// and replace it with diff/2 . now run max heapify
// finally after operation simply pop out the root of the max diff heap

// ceil function
long long int Ceil(double A)
{
    if((A - (int)(A)) > 0)
        return ((int)(A) + 1);
    else
        return A;
}

void max_Heapify(long long int arr[], int i, int heap_size)
{
    int left = 2*i+1;
    int right = 2*i + 2;
    int largest = i;
    if(left < heap_size && arr[left] > arr[i])
        largest = left;
    if(right < heap_size && arr[right] > arr[largest])
        largest = right;
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_Heapify(arr, largest, heap_size);
    }

}
void build_Max_Heap(long long int arr[], int N)
{
    int heap_size = N;
    for (int i = 0; i < (int)(N/2); i++)
    {
        max_Heapify(arr, i, heap_size);
    }
}

int main(int argc, char const *argv[])
{
    int N, k;
    scanf("%d%d", &N, &k);
    long long int A[N];
    long long int A_diff[N-1];
    scanf("%lld", &A[0]);
    for (int i = 1; i < N; i++)
    {
        scanf("%lld", &A[i]);
        A_diff[i-1] = A[i] - A[i-1];
    }

    build_Max_Heap(A_diff, N-1);
    for (int i = 0; i < k; i++)
    {
        A_diff[i] = (long long int)(Ceil(A_diff[i]/2));
        A_diff[i] = A_diff[N-2];
        max_Heapify(A_diff, 0, N-1);
    }
    printf("%lld", A_diff[0]);
    
    
    return 0;
}
