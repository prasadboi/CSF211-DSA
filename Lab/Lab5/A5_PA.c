#include <stdio.h>

struct node
{
    int val;
    int priority;
    int real_loc;
};

// copy function to copy elemnts of struct node
struct node COPY(struct node b)
{
    struct node temp;
    temp.priority = b.priority;
    temp.real_loc = b.real_loc;
    temp.val = b.val;
    return temp;
}

// swap two heap element values
void SWAP(struct node *a, struct node *b)
{
    struct node temp;
    temp = COPY(*a);
    *a = COPY(*b);
    *b = COPY(temp);
}

// helper function to print the heap
void printHeap(struct node arr[], int count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf(" %d %d %d ||",arr[i].real_loc ,arr[i].val, arr[i].priority);
    }
    printf("\n");
}

// min heapify function
void minHeapify(struct node heap[], int i, int heapSize)
{
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;
    int smallest = i;
    
    if(leftChild < heapSize)
    {
        if(heap[leftChild].priority < heap[i].priority)
            smallest = leftChild;
        else if((heap[leftChild].priority == heap[i].priority) && (heap[leftChild].val < heap[i].val))
            smallest = leftChild;
        else if((heap[leftChild].priority == heap[i].priority)&&(heap[leftChild].val == heap[i].val))
            {
                if(heap[leftChild].real_loc < heap[i].real_loc)
                    smallest = leftChild;
            }
    }
    
    if(rightChild < heapSize)
    {
        if(heap[rightChild].priority < heap[smallest].priority)
            smallest = rightChild;
        else if(heap[rightChild].priority == heap[smallest].priority && heap[rightChild].val < heap[smallest].val)
            smallest = rightChild;
        else if(heap[rightChild].priority == heap[smallest].priority && heap[rightChild].val == heap[smallest].val)
            {
                if(heap[rightChild].real_loc < heap[smallest].real_loc)
                    smallest = rightChild;
            }
    }

    if(smallest != i)
    {
        SWAP(&heap[i], &heap[smallest]);
        minHeapify(heap, smallest, heapSize);
    }
}

// building min heap
void buildMinHeap(struct node heap[], int N)
{
    //int heapSize = N;
    for (int i = (int)(N/2); i >= 0; i--)
    {
        //printf("i : %d\n", i);
        minHeapify(heap, i, N);
    }
    
}

int main(int argc, char const *argv[])
{
    int N = 0, heap_size = 0, k = 0;
    scanf("%d%d", &N, &k);
    heap_size = N;
    // creating the heap
    struct node heap[N];
    for (size_t i = 0; i < N; i++)
    {
        scanf("%d%d", &heap[i].val, &heap[i].priority);
        heap[i].real_loc = i;
    }
    //printHeap(heap, N);

    // building the heap
    buildMinHeap(heap, N);
    //printHeap(heap, N);

    // extracting the minimum element of the heap k times
    for (size_t i = 0; i < k; i++)
    {
        if(heap_size == 1)
        {
            printf("%d ", heap[0].real_loc);
            break;
        }

        struct node min = heap[0];
        printf("%d ", min.real_loc);
        heap[0] = COPY(heap[heap_size-1]);
        heap_size--;
        minHeapify(heap, 0, heap_size);
    }
    

    return 0;
}
