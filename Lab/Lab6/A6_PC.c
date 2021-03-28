#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define min(a,b) a>b ? b : a
#define max(a,b) a>b ? a : b
int time[100005];
int n,k;
bool isPossible(int t)
{
    int max_watermelons=0;
    for (int i = 0; i < n; i++)
    {
        max_watermelons+=(t/time[i]);
    }
    if(max_watermelons>=k)
    return true;
    else
    return false;
}
int BinarySearch(int start, int end)
{
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(isPossible(mid))
        {
            end=mid;
            if(start==end)
            return mid;
        }
        else
        {
            start=mid+1;
        }
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    int min_term=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&time[i]);
        min_term=min(min_term,time[i]);
    }
    int min_time=BinarySearch(min_term,k*min_term);
    printf("%d",min_time);
    return 0;
}