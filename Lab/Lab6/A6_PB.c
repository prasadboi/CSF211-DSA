#include <stdio.h>
#include <stdlib.h>

int numPartitions(int arr[], int n)
{
    int _max_ = 0;
    int _min_ = 0;
    int ctr = 0;
    
    for (int i = 0; i < n; i++)
    {

        // calculating maximum of the left partition
        _max_ = arr[0];
        for (int j = 0; j <= i; j++)
        {
            if(_max_ < arr[j])
                _max_ = arr[j];
        }

        // calculating minimum of right partition
        if(i < n-1)
        {_min_ = arr[i+1];
        for (int j = i+1; j < n; j++)
        {
            if(_min_ > arr[j])  
                _min_ = arr[j];
        }
        //printf("%d %d\n", _max_, _min_);
        if(_max_ <= _min_)
            ctr++;}
    }

    return ctr+1;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int h[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &h[i]);
    }
    
    printf("%d", numPartitions(h, N));
    return 0;
}
