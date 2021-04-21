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
    for (int i = 0; i < length;i++){
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

// max heap
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

void swap(ll *a, ll *b)
{
	ll temp = *a;
	*a = *b;
	*b = temp;
}

// max heapify
void max_heapify_down(ll i, ll heap[], ll heap_size)
{
	ll left = get_left_child(i);
	ll right = get_right_child(i);
	ll largest = i;

	if(left <  heap_size && heap[left] > heap[largest])
		largest = left;
	if(right < heap_size && heap[right] > heap[largest])
		largest = right;
	if(largest != i)
	{
		swap(&heap[i], &heap[largest]);
		max_heapify_down(largest, heap, heap_size);
	}
}

//  build max heap
void build_max_heap(ll heap[], ll heap_size)
{
	for(ll i = (ll)(heap_size/2); i >= 0; i--)
	{
		max_heapify_down(i, heap, heap_size);
	}
}

// heap sort
void heap_sort(ll heap[], ll heap_size)
{
	//ll heap_size = N;
	build_max_heap(heap, heap_size);
	for(ll i = heap_size - 1; i >= 1; i--)
	{
		swap(&heap[0], &heap[i]);
		heap_size--;
		max_heapify_down(0, heap, heap_size);
	}
}

int main()
{
    ll num;
	scanf("%lld", &num);
	ll arr[num];
	for(ll i = 0; i  < num; i++)
	{
		scanf("%lld", &arr[i]);
	}
	heap_sort(arr, num);
	print_arr(arr, num);
    return 0;
}
