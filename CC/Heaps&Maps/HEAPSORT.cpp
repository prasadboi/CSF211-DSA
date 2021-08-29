#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void maxHeapify(vector<int> &arr, int i, int heap_size){
    //cout<<"max heapify :=: "<<" i : "<<i<<" heap_size : "<<heap_size<<endl;
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < heap_size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < heap_size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, heap_size);
    }
}

void buildMaxHeap(vector<int> &arr, int heap_size){
    for(int i = heap_size/2-1; i >= 0; i--){
        maxHeapify(arr, i, heap_size);
    }
}

void HeapSort(vector<int> &arr){
    int heap_size = arr.size();
    //cout<<"heap_size : "<<heap_size<<endl;
    buildMaxHeap(arr, heap_size);
    //cout<<"after max heapify : "<<endl;
    for(int i = heap_size - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heap_size--;
        maxHeapify(arr, 0, heap_size);
    }

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> heap(n);
    for(int i = 0; i< n; i++)
    {
        cin>>heap[i];
    }    

    HeapSort(heap);
    for(int i = 0; i < heap.size(); i++){
        cout << heap[i] << " ";
    }
    return 0;
}
