#include <stdio.h>

void maxElementsPossible(int arr[], int x, int budget)
{
    int maxItems = 0;
    for (int i = 0; i < (1<<x); i++)
    {
        int k = 0;
        int sum = 0;
        for (int j = 0; j < x ; j++)
        {
            if (i & (1<<j))
            {
                sum = sum + arr[j];
                if(sum < budget)
                    k++;
            }
            
        }
        if(maxItems < k)
        {
            maxItems = k;
        }
        //printf("\n");
    }
    printf("%d", maxItems);
    
}

int main(int argc, char const *argv[])
{
    int M = 0, N= 0, powOf2 = 0;
    scanf("%d", &M);
    scanf("%d", &N);
    int arr[N];

for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);
maxElementsPossible(arr, N, M);
    return 0;
}
