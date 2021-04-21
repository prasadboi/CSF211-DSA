#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0

void print_arr(ll arr[], ll length)
{
    for (int i = 0; i < length;i++){
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

void swap(ll *a, ll *b)
{
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(ll arr[], ll length)
{
    for (ll i = 0; i < length - 1; i++)
    {
        for (ll j = 0; j < length - i - 1 ; j++)
        {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ll arr[] = {9,8,7,6,5,4,3,2,1,0,10};
    bubble_sort(arr, 11);
    print_arr(arr, 11);
    return 0;
}
