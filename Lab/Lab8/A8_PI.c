#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int 
#define TRUE 1
#define FALSE -1

void print_arr(ll arr[], ll len)
{
    for (ll i = 0; i < len; i++)
    {   
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

void rotate_arr_left(ll arr[], ll len)
{
    ll temp = arr[0];
    for (ll i = 1; i < len; i++)
    {            
        arr[i-1] = arr[i];
    }
    arr[len-1] = temp;
}

ll rotate_to_normal(ll arr[], ll len){
    // calculate the first occurence of min in the array
    ll min_index = 0;
    for (ll i = 1; i < len; i++)
    {
        if(arr[i] < arr[min_index])
            min_index = i;
    }
    printf("min index : %lld\n", min_index);
    for (ll i = 0; i < min_index; i++)
    {
        rotate_arr_left(arr, len);
        //print_arr(arr, len);
    }
}

ll binary_search(ll arr[], ll first, ll last, ll key)
{
    while(first <= last)
    {
        ll mid = (first + last)/2;
        if(arr[mid] == key)
        {
            printf("YES\n");
            return mid;
        }
        else if(arr[mid] > key)
        {
            return binary_search(arr, first, mid-1,key);
        }
        else if(arr[mid] < key)
        {
            return binary_search(arr, mid+1, last, key);
        }
    }
    
    printf("NO\n");
    return FALSE;
}

int main(int argc, char const *argv[])
{
    ll count= 0;
    scanf("%lld", &count);
    ll arr[count]; 
    for (ll i = 0; i < count; i++)
    {
        scanf("%lld", &arr[i]);
    }
    //print_arr(arr,count);
    rotate_to_normal(arr, count);
    //print_arr(arr, count);
    
    ll q = 0;
    scanf("%lld", &q);
    ll k;
    for (ll i = 0; i < q; i++)
    {
        scanf("%lld", &k);
        binary_search(arr, 0, count-1, k);
    }
    
    
    return 0;
}
