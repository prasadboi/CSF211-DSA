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

void insertion_sort(ll arr[], ll length)
{
    ll key, i, j;
    for (i = 0; i < length; i++)
    {
        key = arr[i];
        j = i-1;
        while(j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(int argc, char const *argv[])
{
    ll arr[] = {9,8,7,6,5,4,3,2,1,0,10};
    insertion_sort(arr, 11);
    print_arr(arr, 11);
    return 0;
}
