#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// function to calculate the net-worth of an individual , given string input
unsigned long long int netWorthCalculator(char D[150])
{
    int numStartIndex; 
    int numEndIndex;
    unsigned long long int netWorth = 0;
    for(int i = 0; D[i]!= '\0';)
    {
        // if D[i] is an integer then check if it is the 1st digit of the 
        // of the number, if not check if it is the last digit of the number
        // this way i get the start and end indices of the number

        if(D[0] - 48 >= 0 && D[0] - 48 < 10)
        {
            numStartIndex = 0;
            i++;
        }

        if(D[i] - 48 >= 0 && D[i] - 48 < 10)
        {
            if(!(D[i-1] - 48 >= 0 && D[i-1] - 48 < 10))
            {
                // checking if MSB of the number
                numStartIndex = i;
            }
            if(!(D[i+1] - 48 >= 0 && D[i+1] - 48 < 10))
            {
                // checking if LSB of number
                numEndIndex = i;
                char number[numEndIndex - numStartIndex + 2];
                for (int j = numStartIndex, k = 0; j < numEndIndex + 1; j++, k++)
                {
                    number[k] = D[j];
                    //printf("%c%c ", D[j], number[k]);
                }
                number[numEndIndex - numStartIndex + 1] = '\0';
                //printf("strlen : %d, start index : %d, end index : %d, num : %s\n", numEndIndex - numStartIndex + 1, numStartIndex, numEndIndex ,number);
                netWorth += atoll(number);
            }
            i++;
        }
        else
        {
            i++;
        }
    }
    //printf("\n");

    return netWorth;
}


// function to calculate the top k individual networths

// maxHeapify
void max_Heapify(unsigned long long int arr[], int i, int heap_size)
{
    int left = 2*i+1;
    int right = 2*i + 2;
    int largest = i;
    if(left < heap_size && arr[left] > arr[i])
        largest = left;
    if(right < heap_size && arr[right] > arr[largest])
        largest = right;
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_Heapify(arr, largest, heap_size);
    }
}

// build max heap
void build_Max_Heap(long long int arr[], int N)
{
    int heap_size = N;
    for (size_t i = 0; i < (int)(N/2); i++)
    {
        max_Heapify(arr, i, heap_size);
    }
}

// function that returns the sum of the k largest elements in the heap
unsigned long long int k_Sum(int k, unsigned long long int heap[], int len)
{
    unsigned long long int sum = 0;
    for (int i = 0; i < k; i++)
    {
        //printf("%lld || ", heap[0]);
        sum += heap[0];
        heap[0] = heap[len-1];
        len--;
        max_Heapify(heap, 0, len);
    }
    return sum;
    
}

// print heap
void printHeap(unsigned long long int arr[], int heap_size)
{
    for (int i = 0; i < heap_size; i++)
    {
        printf("%d : %lld || ", i, arr[i]);
    }
    printf("\n");
    
}
// main
int main(int argc, char const *argv[])
{
    int N, k;
    scanf("%d%d", &N, &k);
    unsigned long long int arr[N];
    for (int i = 0; i < N; i++)
    {
        char str[150];
        scanf("%s", str);
        arr[i] = netWorthCalculator(str);
    }
    
    build_Max_Heap(arr, N);
    //printHeap(arr, N);
    printf("%lld", k_Sum(k, arr, N)%(1000000007));
    

    /*unsigned long long int arr[5] = {netWorthCalculator("a1ghe2"), netWorthCalculator("BGH54jk78"), netWorthCalculator("g3267372673hh7"), netWorthCalculator("jhj666SHH7"), netWorthCalculator("apes123strong23together9")};
    //printHeap(arr, 5);
    build_Max_Heap(arr, 5);
    //printHeap(arr, 5);
    printf("\n%lld", k_Sum(3, arr, 5)%(1000000007));*/

    return 0;
}
