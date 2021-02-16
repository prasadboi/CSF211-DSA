#include <stdio.h>
#include <math.h>
int goCrazy(int n,int k)
{
    if(n==0)
    {
        return 1;
    }    
    if(k==0)
    {
        return 1;
    }
    if(n>=pow(2,k))
    {
        int val = pow(2,k);
        return goCrazy((n-val),k)+fun(n,k-1);
    }
    else
    {
        return goCrazy(n,k-1);
    }
}

int main()
{
   int n;
   scanf("%d",&n);
   int k;
   k = log(n)/log(2);
   int num;
   num = goCrazy(n,k);
   printf("%d",num);
   return 0;
}