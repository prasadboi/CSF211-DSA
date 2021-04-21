#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0

// print an array
void print_arr(ll arr[], ll length)
{
    for (ll i = 0; i < length; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");    
}


// swap two ll type values by reference
void swap(ll *a, ll *b) {
    ll temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


// implementing a min heap / priority queue--------------------------------------------------------------------------------------------------------------------------------

// helper functions
ll get_left_child(ll i)
{
    return 2*i + 1;
}

ll get_right_child(ll i)
{
    return 2*i + 2;
}

ll get_parent(ll i)
{
    return (ll)((i - 1)/2);
}


// bottom to top min heaify
void min_heapify_up(ll i, ll heap[], ll heap_size)
{
    // keep on rearranging as long as heap is not correct. stop when correct. do this in a bottom up fashion.
    ll parent = get_parent(i);
    if(parent >= 0 && heap[parent] > heap[i])
    {
        swap(&heap[parent], &heap[i]);
        min_heapify_up(parent, heap, heap_size);
    }
}

/*void build_min_heap_up(ll heap[], ll heap_size)
{
    for(ll i = heap_size-1; i > heap_size/2; i--)
    {
        min_heapify_up(i, heap, heap_size);
    }
}*/

// top to bottom implementaion of min heapify
void min_heapify_down(ll i, ll heap[], ll heap_size)
{
    ll left = get_left_child(i);
    ll right = get_right_child(i);
    ll smallest = i;

    if(left < heap_size && heap[left] < heap[smallest])
    {
        smallest = left;
    }
    if(right < heap_size && heap[right] < heap[smallest])
    {
        smallest = right;
    }
    if(smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        min_heapify_down(smallest, heap, heap_size);
    }
}

void build_min_heap_down(ll heap[], ll heap_size)
{
    for(ll i = (ll)(heap_size/2); i >= 0; i--)
    {
        min_heapify_down(i, heap, heap_size);
    }
}

ll peek(ll heap[], ll (*heap_size))
{
    if((*heap_size) > 0)
        return heap[0];
    else
    {
        printf("heap is empty!!!\n");
        return -1000000007;
    }
}

ll poll(ll heap[], ll (*heap_size))
{
    ll root = heap[0];
    heap[0] = heap[(*heap_size)-1];
    heap_size--;
    min_heapify_down(0, heap, heap_size);
    return root;
}

ll insert(ll heap[], ll *heap_size, ll val)
{
    (*heap_size)++;
    heap[(*heap_size)-1] = val;
    min_heapify_up((*heap_size)-1, heap, (*heap_size));
}

//------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{

    ll heap[11] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    build_min_heap_down(heap, 10);
    print_arr(heap, 10);
    insert(heap, 10, -1);
    print_arr(heap, 11);
    return 0;
}