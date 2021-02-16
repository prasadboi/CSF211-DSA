#include <stdio.h>
#include <ctype.h>
//#include <math.h>

int Ceil(float N)
{
    float temp = N;
    if(N - (int)(N) > 0)
        return ((int)(N) + 1);
    else
        return ((int)(N));

}
int main()
{
    float N;
    float C;
    char c;
    int sum = 0 ;
    int arr[35];
    char S[20];
    for(int i = 0;i<35;i++){
        arr[i] = 0;
    }
    scanf("%f",&N);
    scanf("%f",&C);
    if(C == 0){
        return 0;
    }
    for(int i = 0;i<N;i++){
        scanf("%s",S);

        if(isdigit(S[0])!= 0){
            int check = S[0] - 48;
            arr[check]++;
        }
        else if(isalpha(S[0])!= 0){
            int check = S[0] - 55;
            arr[check]++;
        }
    }
    for(int i = 0;i<=35;i++){
        if(arr[i] > C){
            float temp = ((float)arr[i] - C)/(float)C;
            int val = Ceil(temp) + 1;
            //printf("%d\n",val);
            int add = (arr[i] - C*(val - 1))*val*(val - 1)+(C - arr[i]+C*(val - 1))*(val - 1)*(val - 2);

            sum = sum + add/2;
        }
    }
    printf("%d",sum);
    return 0;
}