#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define ll long long int

ll largest_subarray_sum(ll arr[], ll len)
{
    ll max = INT_MIN;
    ll curr_max = 0;

    for (int i = 0; i < len; i++)
    {
        curr_max += arr[i];
        if(curr_max > max)
        {
            max = curr_max;
        }
        if (curr_max < 0)
        {
            curr_max = 0;
        }
    }
    return max;
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
    printf("%lld", largest_subarray_sum(arr, count));
    return 0;
}
