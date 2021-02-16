#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkPrime(int num)
{
    //printf(" CHECKPRIME CALLED!");
    int flag = 1;
    for(long int i = 2; i <= (long int)(sqrt(num)); i++)
    {
        if((num%i) == 0){
            flag = 0;
        }
    }
    //printf("flag : %d", flag);
    return flag;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x; 
    *x = *y;
    *y = temp;
}

int main()
{
    long int X, Y;
    scanf("%ld %ld", &X, &Y);
    //printf("%ld %ld\n", X, Y);
    if((Y - X) < 0)
        swap(&X, &Y);
    if(X > pow(10, 12) || Y > pow(10, 12) || Y < 0 || X < 0 || (Y - X) > pow(10, 6))
        exit(0);
    
    int numFrequency[10] = {0,0,0,0,0,0,0,0,0,0};
    int maxFreq = 0, maxFreqIndex;
    for(long int i = X; i <= Y; i++)
    {
        //printf(" %d \n", i);
        if(checkPrime(i) == 1)
        {
            //printf("PRIME!");
            long int num = i;
            //printf("\n%d\n", num);
            while(num > 0)
            {
                numFrequency[num%10]++;
                num = num/10;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if(maxFreq < numFrequency[i])
        {
            maxFreq = numFrequency[i];
            maxFreqIndex = i;
        }
    }

    printf("%d %d", maxFreqIndex, maxFreq);
    return 0;
}
