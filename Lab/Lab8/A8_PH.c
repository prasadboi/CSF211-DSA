#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int

// brute force approach ;)
ll largest_subarray_sum_zero(ll arr[], ll length)
{
    ll sum = 0;
    ll count = 0;
    ll max_count = 0;
    for (ll i = 0; i < length; i++)
    {
        // printf("i : %lld\n", i);
        count = 0;
        sum = 0;
        for (ll j = i; j < length; j++)
        {
            sum += arr[j];
            //printf("sum : %lld\n", sum);
            count++;
            if(sum == 0)
            {
                //printf("count : %d\n", count);
                if(max_count < count)
                {
                    max_count = count;
                }
            }
        }
    }
    
    return max_count;
}

int main(int argc, char const *argv[])
{
    ll count = 0;
    scanf("%lld", &count);
    ll arr[count];
    for (int i = 0; i < count; i++)
    {
        scanf("%lld", &arr[i]);
    }
    printf("%lld", largest_subarray_sum_zero(arr, count));
    return 0;
}
