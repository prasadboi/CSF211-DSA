

// https://stephenjoel2k.medium.com/two-heaps-min-heap-max-heap-c3d32cbb671d

#include <stdio.h>

/*void print_heap(int heap[], int heap_size)
{
    for (int i = 0; i < heap_size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    
}*/

// Max_heap
// maxHeapify------------------------------------------------------------------
void max_Heapify_UpDown(int arr[], int i, int heap_size)
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
        max_Heapify_UpDown(arr, largest, heap_size);
    }

}
//---------------------------------------------------------------------------


//Min_Heap
// min_heapify------------------------------------------------------

void min_Heapify_UpDown(int arr[], int i, int heap_size)
{
    int left = 2*i+1;
    int right = 2*i + 2;
    int smallest = i;
    if(left < heap_size && arr[left] < arr[i])
        smallest = left;
    if(right < heap_size && arr[right] < arr[smallest])
        smallest = right;
    if(smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        min_Heapify_UpDown(arr, smallest, heap_size);
    }

}
//-------------------------------------------------------------------------------

// finding median given a data stream ------------------------------------------------------
void balance_heaps(int min_heap[], int max_heap[], int *min_heap_size, int *max_heap_size)
{
    if(*max_heap_size > (*min_heap_size) + 1)
    {
        //printf("max heap size > min heap size + 1\n");
        min_heap[*min_heap_size] = max_heap[0];
        (*min_heap_size)++;

        /*int temp = min_heap[0];
        min_heap[0] = min_heap[(*min_heap_size) - 1];
        min_heap[(*min_heap_size) - 1] = temp;*/
        for (int i = (int)((*min_heap_size) / 2); i >= 0; --i) min_Heapify_UpDown(min_heap, i, *min_heap_size);

        max_heap[0] = max_heap[(*max_heap_size)-1];
        (*max_heap_size)--;
        max_Heapify_UpDown(max_heap, 0, *max_heap_size); // deleting the root of the max_heap
    }

    else if(*max_heap_size < *min_heap_size)
    {
        //printf("min heap size > max heap size\n");
        max_heap[*max_heap_size] = min_heap[0];
        (*max_heap_size)++;
       
        /*int temp = max_heap[0];
        max_heap[0] = max_heap[(*max_heap_size) - 1];
        max_heap[(*max_heap_size) - 1] = temp;*/
        for (int i = (int)((*max_heap_size) / 2); i >= 0; --i) max_Heapify_UpDown(max_heap, i, *max_heap_size);

        min_heap[0] = min_heap[(*min_heap_size)-1];
        (*min_heap_size)--;
        min_Heapify_UpDown(min_heap, 0, *min_heap_size);
    }
}

void insert(int min_heap[], int max_heap[], int *min_heap_size, int *max_heap_size, int num)
{
    //printf("num is %d \n", num);
    if(*max_heap_size == 0 || num < max_heap[0])
    {
        //printf("num < max heap root\n");
        max_heap[*max_heap_size] = num;
        (*max_heap_size)++;

        /*int temp = max_heap[0];
        max_heap[0] = max_heap[(*max_heap_size) - 1];
        max_heap[(*max_heap_size) - 1] = temp;*/
        for (int i = (int)((*max_heap_size) / 2); i >= 0; --i) max_Heapify_UpDown(max_heap, i, *max_heap_size);
    }
    else
    {
        //printf("num > max heap root\n");
        min_heap[*min_heap_size] = num;
        (*min_heap_size)++;

        /*int temp = min_heap[0];
        min_heap[0] = min_heap[(*min_heap_size) - 1];
        min_heap[(*min_heap_size) - 1] = temp;*/
        for (int i = (int)((*max_heap_size) / 2); i >= 0; --i) min_Heapify_UpDown(min_heap, i, *min_heap_size);
    }


    /*printf("max heap size : %d\n", *max_heap_size);
    print_heap(max_heap, *max_heap_size);
    printf("min heap size: %d \n", *min_heap_size);
    print_heap(min_heap, *min_heap_size);*/
    balance_heaps(min_heap, max_heap, min_heap_size, max_heap_size);
    /*printf("max heap size : %d \n", *max_heap_size);
    print_heap(max_heap, *max_heap_size);
    printf("min heap size: %d \n", *min_heap_size);
    print_heap(min_heap, *min_heap_size);*/
}

float median(int min_heap[], int max_heap[], int *min_heap_size, int *max_heap_size)
{
    if(*max_heap_size == *min_heap_size)
    {
        return (float)((max_heap[0] + min_heap[0]) / 2);
    }
    else
    {
        return max_heap[0];
    }
}

//----------------------------------------------------------------------
//--------------------------------------------------------------------
int main(int argc, char const *argv[])
{
    int N;
    int min_heap_size = 0; 
    int max_heap_size = 0;

    scanf("%d", &N);

    int min_heap[N], max_heap[N], arr[N];
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        //printf("arr[i] : %d \n", arr[i]);
        insert(min_heap, max_heap, &min_heap_size, &max_heap_size, arr[i]);
        printf("%ld ", (long int)median(min_heap, max_heap, &min_heap_size, &max_heap_size));
    }
    return 0;
}