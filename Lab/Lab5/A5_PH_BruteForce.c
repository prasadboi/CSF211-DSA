#include<stdio.h>
 
void swap(int *xp, int *yp) 
{ 
    long long temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void max_heapify(int arr[], int i, int n)
{
    int left=2*i+1;
    int right = 2*i + 2;
    int largest=0;
    if(left<=(n-1) && arr[left]>arr[i])
    {
        largest=left;
    }
    else
    {
        largest=i;
    }
    if(right<= (n-1) && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        max_heapify(arr,largest,n);
    }
    
}
void build_max_heap(int arr[], int n)
{
    for (int i = (n/2) ; i >= 1; i--)
    {
        max_heapify(arr,i-1,n);   
    }
}
 
void heap_sort(int arr[], int n)
{
    build_max_heap(arr,n);
    int heap_size = n;
    for (int i = n; i >=2; i--)
    {
        swap(&arr[0],&arr[i-1]);
        heap_size--;
        max_heapify(arr,0,heap_size);
    }
}


void median(int arr[],int size)
{
    heap_sort(arr,size);
    if(size%2==1)
    {
    int median=arr[size/2];
   printf("%d",median);
	}
   else
    {
        int median=(arr[size/2]+(arr[(size/2)-1]))/2;
	    printf("%d",median);
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],brr[n],j=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        brr[j++]=arr[i];
        median(brr,j);
        printf(" ");
    }
    median(arr,n);
    return 0;
}