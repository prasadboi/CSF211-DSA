#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0
#define LL_MAX 1000000007

void print_arr(ll arr[], ll length)
{
    for (ll i = 0; i < length;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// MERGE_SORT--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void merge(ll arr[], ll temp[], ll start, ll mid, ll end){
    
    //
    ll L_size = mid - start + 1;
    ll R_size = end - start;


    ll left = start;
    ll right = mid + 1;
    ll ctr = start;
    // copy left and right subarrays into temp
    while(left <= mid && right <= end)
    {
        if(arr[left] < arr[right])
        {
            temp[ctr] = arr[left];
            ctr++;
            left++;
        }
        else
        {
            temp[ctr] = arr[right];
            ctr++;
            right++;
        }
    }

    // copying the remaining elements into temp
    for (; left <= mid; left++)
    {
        temp[ctr] = arr[left];
        ctr++;
    }
    for(; right <= end; right++)
    {
        temp[ctr] = arr[right];
        ctr++;
    }

    // copy all of temp into arr
    ctr = start;
    for(; ctr <= end; ctr++)
    {
        arr[ctr] = temp[ctr];
    }
}

void merge_sort(ll arr[], ll temp[], ll start, ll end)
{    
    ll mid = (start+end)/2;   
    if(start >= end){
        return;
    }
    
    // left half
    merge_sort(arr, temp, start, mid);
    // right half
    merge_sort(arr, temp, mid+1, end);
    // merge halves
    merge(arr, temp, start, mid, end);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

ll main(ll argc, char const *argv[])
{
    ll arr[] = {9,8,7,6,5,4,3,2,1,0,10};
    ll temp[11];
    //merge(arr, temp, 0, 5, 10);
    //print_arr(arr, 11);
    merge_sort(arr, temp, 0,10);
    print_arr((arr), 11);
    return 0;
}
