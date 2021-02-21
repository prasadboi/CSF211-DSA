#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//-----------------------------------------------
//quicksort
int Partition(int arr[], int P, int R)
{
    int temp;
    int X = arr[R];
    int i = P - 1;
    for (int j = P; j <= R-1; j++)
    {
        if(arr[j] <= X)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i + 1] = arr[R];
    arr[R] = temp;

    return (i+1);
}

void quickSort(int arr[], int P, int R)
{
    if(P < R)
    {
        int Q = Partition(arr, P, R);
        quickSort(arr, P, Q-1);
        quickSort(arr, Q+1, R);
    }
}
//-------------------------------------------------


int ternary_Search(int l, int r, int search, int arr[])
{
    if (r >= l)
    {
        int mid_1 = l + (r - l) / 3;
        int mid_2 = r - (r - l) / 3;
 
        if (search == arr[mid_1]) 
        {
            printf("YES\n");
            return mid_1;
        }
        if (search == arr[mid_2]) {
            printf("YES\n");
            return mid_2;
        }

        // Dealing with ranges in which search can lie
        if (search < arr[mid_1])
        {
            return ternary_Search(l, mid_1 - 1, search, arr);
        }
        else if ((search < arr[mid_2])&&(search > arr[mid_1])) 
        { 
            return ternary_Search(mid_1 + 1, mid_2 - 1, search, arr);
        }
        else 
        {
            return ternary_Search(mid_2 + 1, r, search, arr);
        }
    }
    printf("NO\n");
    return -1;
}

/*
void print_arr(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
*/
int main(int argc, char const *argv[])
{

    int N, M;
    scanf("%d%d", &N, &M);
    int notes[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &notes[i]);
    }
    //print_arr(notes, N);
    int tone[M];
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &tone[i]);
    }
    //print_arr(tone, M);
    quickSort(notes, 0, N-1);

    
    for (int i = 0; i < M; i++)
    {
        //printf("%d : ", i);
        ternary_Search(0, N-1, tone[i], notes);
    }
    return 0;
}
