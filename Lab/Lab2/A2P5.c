#include <stdio.h>
#include <math.h>
int main()
{
    int N;
    int K;
    scanf("%d",&N);
    scanf("%d",&K);
    char c[N];
    int u[K];
    for(int i = 0;i<K;i++){
        u[i] = 0;
    }
    for(int i = 0;i<N;i++){
        scanf(" %c",&c[i]);
    }
    int m = 0;
    for(int i = 0 ;i<pow(N,K);i++)
    {
        char a[K];
        for(int j = 0;j<K;j++){
            if(u[j] >= pow(N,K-j)){
                u[j] = 0;
            }
            
            int res = (int)(u[j]*(N))/(pow(N,(K-j)));
            a[j] = c[res];
            u[j]++;
            
        }
       
        for (int i = 0; i < K; i++)
        {
            printf("%c", a[i]);
        }
        
        printf("\n");
        
    }
    return 0;
}
