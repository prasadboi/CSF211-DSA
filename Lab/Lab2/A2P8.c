#include <stdio.h>
#include <math.h>
int main()
{
   int n;
   int sum = 0;
   scanf("%d",&n);
   int arr[n];
   for(int i = 0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
   for(int i = 0;i<n;i++)
   {    
       int level = log(i+1)/log(2);
       sum = sum + arr[i]*(level+1);
   }    
   printf("%d",sum);
   return 0;
}
