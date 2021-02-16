#include <stdio.h>
#include <math.h>

void rotateRight(int arr[], int len)
{
    int temp = arr[len - 1];
    for (int i = len - 1; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}
int computeCost(int arr[], int len)
{
    long int cost;
    long int odd_sum = 0, even_sum = 0;
    for (int i = 0; i < len; i++)
    {
        if(i%2 == 0)
        {
            even_sum += arr[i]*arr[i];
        }
        else
        {
            odd_sum += arr[i]*arr[i]*arr[i];
        }
    }
    cost = (even_sum - odd_sum);
    
    return cost;
}
int main(int argc, char const *argv[])
{
    int len = 0;
    scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }

    long int max_cost = computeCost(arr, len), min_cost = computeCost(arr, len);

    for (int i = 0; i < len - 1; i++)
    {
        int cost = computeCost(arr, len);
        if (max_cost < cost)
        {
            max_cost = cost;
        }
        if(min_cost > cost)
        {
            min_cost = cost;
        }
        rotateRight(arr, len);
    }
    
    
    /*for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }*/

    //printf("\nmaxCost : %d, minCost : %d\n", max_cost, min_cost);
    printf("%ld", max_cost - min_cost);
    
    
    return 0;
}
