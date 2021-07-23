#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void print_Array(int arr[], int arr_size){ 
    for (int i = 0; i < arr_size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int compare(const void* ap, const void* bp)
{
    const int* a = (int*)ap;
    const int* b = (int*)bp;
 
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 7, 9, 6, 8, 5, 4, 1, 2, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr + arr_size);
    print_Array(arr,arr_size);
    //sort(arr, arr + arr_size, greater<int>());
    //print_Array(arr, arr_size);
    

    int key = 9;
    // Calling std::bsearch
    // Typecasting the returned pointer to int
    int* p2 = (int*)bsearch(&key, arr, arr_size, sizeof(arr[0]), compare);
    // If non-zero value is returned, key is found
    if (p2)
        cout << key << " found at position " << (p2 - arr) << '\n';
    else
        cout << key << " not found\n";
        
    return 0;
}
