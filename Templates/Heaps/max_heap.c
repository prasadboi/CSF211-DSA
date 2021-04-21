#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOl int
#define TRUE 1
#define FALSE 0

// print an array
void print_array(ll arr[], ll length){
    for(ll i = 0; i < length; i++){
        printf("%lld ", arr[i]);
    }
    printf("\n");
}


// MAX HEAP ----------------------------------------------------------------------------------------------------------------------------------------------------------------

// helper functions
void swap(ll *a, ll *b){
    ll temp;
    temp =  *a;
    *a = *b;
    *b = temp;
}

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
    return (ll)((i-1)/2);
}

// max heap with top to bottom implementation
void max_heapify_down(ll i, ll heap[], ll heap_size)
{
    ll left = get_left_child(i);
    ll right = get_right_child(i);
    ll largest = i;

    if((left < heap_size) && heap[largest] < heap[left])
        largest = left;
    if((right < heap_size) && heap[largest] < heap[right])
        largest = right;
    if(largest != i)
    {
        swap(&heap[largest], &heap[i]);
        max_heapify_down(largest, heap, heap_size);
    }
}

void build_max_heap(ll heap[], ll heap_size)
{
    for(ll i = (heap_size/2); i >= 0; i--){
        max_heapify_down(i, heap, heap_size);
    }
}


// max heap with bottom to top implementation
void max_heapify_up(ll i, ll heap[], ll heap_size){
    ll parent = get_parent(i);
    if(parent >= 0 && heap[parent] < heap[i])
    {
        swap(&heap[parent], &heap[i]);
        max_heapify_up(parent, heap, heap_size);
    }
}



// insert into a max heap
void insert(ll val, ll heap[], ll *heap_size)
{
    heap_size++;
    heap[*heap_size-1] = val;
    max_heapify_up((*heap_size)-1, heap, (*heap_size));
}

// you can also insert as follows
/*
void insert(ll val, ll heap[], ll heap_size)
{
    heap_size++;
    heap[heap_size - 1] = val;
    swap(&heap[0], &heap[heap_size-1]);
    build_max_heap(heap, heap_size);
}
*/

// show the root of the heap
ll peek(ll heap[], ll heap_size)
{
    if(heap_size > 0)
    {
        return heap[0];
    }
    else
    {
        printf("The heap is empty !!!\n");
        return -1000000007;
    }
}

ll poll(ll heap[], ll *heap_size)
{
    ll root = heap[0];
    heap[0] = heap[(*heap_size)-1];
    (*heap_size)--;
    max_heapify_down(0, heap, *heap_size);
    return root;
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    ll heap[11] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    ll heap_size = 10;
    build_max_heap(heap, heap_size);
    print_array(heap, heap_size);
    insert(900, heap, &heap_size);
    print_array(heap, heap_size);
    return 0;
}