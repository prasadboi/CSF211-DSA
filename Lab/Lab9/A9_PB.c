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

void frequency_arr(ll freq_arr[], ll arr[], ll length, ll min, ll max) 
{
    //printf("calling frequency_arr() function\n");
    for (ll i = 0; i < length; i++)
    {
        freq_arr[arr[i] - min]++;
    }
}

ll max_num_elements_delete(ll freq_arr[], ll arr[], ll length, ll min, ll max)
{
    //printf("calling max_num_elements_delete() function\n");
    ll count = 0;
    for (ll i = 0; i < length; i++)
    {
        if(arr[i] != freq_arr[arr[i] - min])
        {
            //printf("arr[i] is not equal to freq_arr[arr[i] - min], where the min = %lld\n", min);
            if(arr[i] > freq_arr[arr[i] - min])
            {
                //printf("arr[i] = %lld is greater than freq[arr[i] - min] = %lld\n", arr[i], freq_arr[arr[i] - min]);
                count++;
            }
            else if(arr[i] < freq_arr[arr[i] - min])
            {
                //printf("arr[i] = %lld is lesser than freq[arr[i] - min] = %lld\n", arr[i], freq_arr[arr[i] - min]);
                while(freq_arr[arr[i] - min] != arr[i])
                {
                    freq_arr[arr[i] - min]--;
                    count++;
                }
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    ll length = 0;
    scanf("%lld", &length);
    ll max = INT_MIN;
    ll min = INT_MAX;
    ll arr[length];
    for (ll i = 0; i < length; i++)
    {
        ll x;
        scanf("%lld", &x);
        if(x > max)
            max = x;
        else if(x < min)
            min = x;
        arr[i] = x;
    }
    ll freq_arr[max - min + 1];
    for (ll i = 0; i < max - min  + 1; i++)
        freq_arr[i] = 0;
    frequency_arr(freq_arr, arr, length, min, max);
    //print_array(freq_arr, max - min + 1);
    printf("%lld", max_num_elements_delete(freq_arr, arr, length, min, max));
    
    return 0;
}
