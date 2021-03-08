#include <stdio.h>
//Merge Sort-------------------------------------------------------------------------------------------
int merge(int arr[], int temp[], int beg, int mid, int end) 
{
    int i = beg;
    int j = mid;
    int k = beg;
    int ctr = 0;

    while ((i <= mid - 1) && (j <= end)) 
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];

        else 
        {
            temp[k++] = arr[j++];
            ctr += (mid - i);
        }
    }
    while (i <= mid - 1) 
    {
        temp[k++] = arr[i++];
    }
    while (j <= end) 
    {
        temp[k++] = arr[j++];
    }

    for (int i = beg; i < end; i++) 
    {
        arr[i] = temp[i];
    }

    return ctr;
}
int mergeSort(int arr[], int temp[], int start, int end) {
    int mid, ctr = 0;
    if (end > start) {
        mid = (start + end) / 2;

        ctr += mergeSort(arr, temp, start, mid);
        ctr += mergeSort(arr, temp, mid + 1, end);
        ctr += merge(arr, temp, start, mid + 1, end);
    }

    return ctr;
}
//--------------------------------------------------------------------------------------

int main() {
    int num;
    scanf("%d", &num);
    int arr[num], x[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d", mergeSort(arr, x, 0, num - 1));
    return 0;
}