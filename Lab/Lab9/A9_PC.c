#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0

void print_array(ll arr[], ll length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

ll calc_max_even(ll arr[], ll length)
{
    ll max_even = INT_MIN;
    for (ll i = 0; i < length; i++)
    {
        if((max_even < arr[i]) && (arr[i]%2==0))
        {
            max_even = arr[i];
        }
    }
    return max_even;
}

void min_move_escape_world(ll arr[], ll length)
{
    ll count = 0;
    BOOL flag = TRUE;
    
    while(flag == TRUE)
    {
        flag = FALSE;
        ll max_even = calc_max_even(arr, length);
        if(max_even != INT_MIN)
        {
            for (ll i = 0; i < length; i++)
            {
                if(arr[i] == max_even)
                {
                    arr[i] = arr[i]/2;
                    //count++;
                    flag = TRUE;
                }
            }
        }
        else
            break;
        //print_array(arr, length);
        count++;
    }
    printf("%lld", count);
}

int main(int argc, char const *argv[])
{
    ll arr[] = {40, 6, 40, 3, 20, 1};
    min_move_escape_world(arr, 6);
    return 0;
}
