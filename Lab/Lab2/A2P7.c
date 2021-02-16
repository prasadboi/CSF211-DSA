#include <stdio.h>
#include<math.h>

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && key < arr[j]) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

/*
void printArr(int arr[], int N)
{
    for (int i = 0; i < N ; i++)
    {
        printf("%d ", arr[i]);
    }
    
}*/
int FillBoxes(int arr[], int N, int maxWt)
{
    int minBox = 0;
    int flag = 0;
    insertionSort(arr, N);
    //printf("SORTED ARRAY \n");
    //printArr(arr, N);
    //printf("\n");

    for (int i = N-1; i >=0; i--)
    {
        if(arr[i] != -1){
        int flag = 0; // var to check if a pair can be made in the first place

        for (int j = i-1; j >= 0 ; j--)
        {
            //printf(" j is : %d ,", j);
            if(((arr[i] + arr[j]) <= maxWt )&&(arr[i] != -1)&&(arr[j] != -1))
            {
                //printf("%d + %d <= %d", arr[i], arr[j], maxWt );
                arr[i] = -1;
                arr[j] = -1;
                //printArr(arr, N);
                //printf("\n");
                minBox++;
                flag = 1;
                break;
            }

        }
        if(flag ==0)
        {
            // means that no pair can be found for the box
            //printf("Flag was 0 \n");
            minBox++;
        }
        }
    }
    return minBox;
    
}

int main(int argc, char const *argv[])
{
    int N, maxWt;
    scanf("%d", &N);
    int arrOfWts[N];
    int box;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arrOfWts[i]);
    }
    scanf("%d", &maxWt);
    printf("%d", FillBoxes(arrOfWts, N, maxWt));
    

    return 0;
}
