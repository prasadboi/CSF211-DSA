#include <stdio.h>
#include <stdlib.h>

#define ll long long int

// print array
void print_arr(ll arr[], ll length)
{
	for(ll i = 0; i < length; i++)
	{
		printf("%lld ", arr[i]);
	}
}

// swap
void swap(ll *a, ll *b)
{
	ll temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// partition
ll partition(ll arr[], ll start, ll end)
{
	ll pivot = arr[start];
	ll i = start + 1;
	ll j = start + 1;

	for(; j < end+1; j++)
	{

		if(arr[j] < pivot)
		{
			swap(&arr[j], &arr[i]);
			i++;
		}
	}

	// place pivot back in correct in location
	swap(&arr[start], &arr[i-1]);
	return i-1;
}

// quicksort
void quick_sort(ll arr[], ll start, ll end)
{
	if(start >= end)
		return;
	
	ll pivot = partition(arr, start, end);
	quick_sort(arr, start, pivot);
	quick_sort(arr, pivot + 1, end);
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
	quick_sort(arr, 0, num-1);
	print_arr(arr, num);

}



