#include <stdio.h>

int weirdFunc(int num)
{
    int maxDiv1 = 1, maxDiv2 = 1;
    for (int i = 2; i <= (num/2); i++)
    {
           if(num% i == 0)
           {
               maxDiv1 = i;
           }
    }
    //printf(" %d ", maxDiv1);
    for (int i = 2; i < maxDiv1; i++)
    {
        if(num % i == 0)
        {
            maxDiv2 = i;
        }
    }
    //printf(" %d ", maxDiv2);
    if((maxDiv1 == 1)||(maxDiv2 == 1))
    {
        return num;
    }
    else
    {
        return (weirdFunc(maxDiv1) + weirdFunc(maxDiv2));
    }
    
    
}
int main(int argc, char const *argv[])
{
    int num = 0;
    scanf("%d", &num);
    printf("%d", weirdFunc(num));
    return 0;
}
