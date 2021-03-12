#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// creating a max heap
void max_heapify(int arr[], int i, int heap_size)
{
    int left = 2*i + 1;
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
        max_heapify(arr, largest, heap_size);
    }
}

void build_max_heap(int arr[], int n)
{
    int heap_size = n;
    for (int i = 0; i < (int)(heap_size/2); i++)
    {
        max_heapify(arr, i, heap_size);
    }
}

int insert_Rootby3_intoMaxHeap_andRetRoot(int heap[], int *heap_size)
{
    int root = heap[0];
    heap[0] = heap[0]/3;
    max_heapify(heap, 0, (*heap_size));
    return root;
}

void howManyChocolates(int heap[], int heap_size, int num_days)
{
    long long int total_choc = 0;
    for (int i = 0; i < num_days; i++)
    {
        total_choc += insert_Rootby3_intoMaxHeap_andRetRoot(heap, &heap_size);
    }
    printf("max total number of chocolates that can be eaten : %lld \n", total_choc);
}

void scanArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int num_bowls = 0, num_days = 0;
    scanf("%d%d", &num_bowls, &num_days);
    int choco_heap[num_bowls];
    scanArray(choco_heap, num_bowls);
    build_max_heap(choco_heap, num_bowls);
    howManyChocolates(choco_heap, num_bowls, num_days);
    return 0;
}
