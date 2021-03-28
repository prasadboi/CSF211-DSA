#include <stdio.h>

//problem F of assignment 6

int main(int argc, char **argv){
    int N, T;
    int start[T], end[T];
    int cumulative = 0;
    scanf("%d%d", &N, &T);

    int baseArray[N];
    
    for(int i = 0; i < N; i++){
        scanf("%d", &baseArray[i]);
    }

    for(int i = 0; i < T; i++){
        int k = 0;
        scanf("%d", &k);

        cumulative += k;
        //printf("%d", cumulative);
        int mod = cumulative % N;
        if(mod != 0)
        {
            printf("%d %d\n", baseArray[mod], baseArray[mod - 1]);
            /*start[i] = baseArray[mod];
            end[i] = baseArray[mod-1];*/
        }
        else
        {
            /*start[i] = baseArray[0];
            end[i] = baseArray[N-1];*/
            printf("%d %d\n", baseArray[0], baseArray[N-1]);
        }
    }

    //printf("%d %d", start, end);
    /*for (int i = 0; i < T; i++)
    {
        if(i != T-1)
            printf("%d %d\n", start[i], end[i]);
        else
            printf("%d %d", start[i], end[i]);
    }*/

    return 0;
}