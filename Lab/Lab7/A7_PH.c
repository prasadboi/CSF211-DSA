#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

#define ll long long int

ll ABS(ll a)
{
    if(a < 0)
        return -a;
    else
        return a;
}

ll power(ll a, ll i)
{
    ll a_pow_i = 1;
    for (int j = 1; j <= i; j++)
    {
        a_pow_i *= a;
    }
    return a_pow_i;
}

ll left_view_sum(ll arr[], ll size){

    ll sum = 0;
    if(arr[0] != -1)
    {
        sum = arr[0];
        //printf("\nleft view element for layer 0 is %lld\n", arr[0]);
    }
    else
        return 0;
    
    ll ctr = 1;
    for (int i = 1; i < size; i++)
    {
        if(i == (power(2, ctr) - 1))
        {
            while(arr[i] == -1)
            {
                i++;
            }
            if(i == (power(2, ctr+1) - 1))
                return sum;
            //printf("left view element for layer %lld is %lld\n", ctr, arr[i]);
            sum = sum + arr[i];
            ctr++;
        }
    }
    return sum;
}

ll right_view_sum(ll arr[], ll size)
{
    ll sum = 0;
    if(arr[0] != -1)
    {
        sum = arr[0];
        //printf("\nright view element for layer 0 is %lld\n", arr[0]);
    }
    else
        return 0;


    ll ctr = 1;
    for (int i = 1; i < size; i++)
    {
        if(i == (power(2, ctr+1) - 2))
        {
            while (arr[i] == -1)
            {
                i--;
            }
            if(i == (power(2, ctr) - 2))  
                return sum;
            //printf("right view element for layer %lld is %lld\n", ctr, arr[i]);
            sum += arr[i];
            ctr++;
        }
    }
    // taking into consideration the last layer,
    // where last element of the array must also be
    // the rightmost element of the tree, but is not accomodated by the loop above
    for (int i = size - 1; i >= power(2, ctr)-1; i--)
    {
        if(arr[i] != -1)
        {
            //printf("right view element for layer %lld is %lld\n", ctr, arr[i]);
            sum += arr[i];
            break;
        }
    }
    
    return sum;
}

int main(int argc, char const *argv[])
{

    ll size;
    scanf("%lld", &size);
    ll A[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%lld", &A[i]);
    }

    int i = size-1;
    while (A[i] == -1)
    {
        i--;
        size--;
    }
    
    //printf("new size : %lld\n", size);
    
    printf("%lld", ABS(left_view_sum(A, size) - right_view_sum(A, size)));
    return 0;
}
