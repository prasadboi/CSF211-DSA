#include <stdio.h>
#include <math.h>
int glo = 0;
int abs(int n){
    if(n > 0){
        return n;
    }
    else{
        return 0 - n;
    }
}

void check(int c,int N,int X[],int Y[],int pow[]){

    int left = 0;
    int right = 0;
    for(int i = 0;i<N;i++){
        if(Y[i]-X[i]-c > 0){
            right = right + pow[i];
        }
        else{
            left = left + pow[i];
        }
    }
    int ca = right - left;
    if(ca == 0){
        printf("Yes");
        return;
    }
    else if(ca > 0 && glo != 2){
        glo = 1;
        int min_x = 0;
        int min_y = 0;
        int ind;
        int min_d = 0;
        for(int k = 0;k<N;k++){
            if(Y[k] - X[k] - c > 0){
                int d = abs(Y[k] - X[k] - c)/sqrt(2);
                if(d > min_d){
                    min_x = X[k];
                    min_y = Y[k];

                }
            }
        }
        c = min_y - min_x;
        check(c,N,pow,X,Y);
    }
    else if(ca > 0 && glo == 2){
        printf("NO");
        return;
    }
    else if(ca < 0 && glo!=1){
        glo = 2;
        int min_x = 0;
        int min_y = 0;
        int min_d = 0;
        for(int k = 0;k<N;k++){
            if(Y[k]-X[k]-c <= 0){
                int d = abs(Y[k]-X[k]-c)/sqrt(2);
                if(d > min_d){
                    min_x = X[k];
                    min_y = Y[k];
                }
            }
        }
        c = min_y - min_x;
        check(c,N,pow,X,Y);
    }
    else if(ca < 0 && glo == 1){
        printf("NO");
        return;
    }
}
int main(){
    int T;

    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        int N;

        scanf("%d",&N);
        int pow[N];
        int X[N];
        int Y[N];
        float c = 0.0;
        for(int j = 0;j<N;j++){
            scanf("%d",&X[j]);
            scanf("%d",&Y[j]);
            scanf("%d",&pow[j]);
        }
        check(c,N,pow,X,Y);
    }
    return 0;
}