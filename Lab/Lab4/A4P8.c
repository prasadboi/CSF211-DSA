#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

int distinct(char str[]){
    int count = 0;

    for(int i = 0; i < strlen(str); i++){
        bool appears = false;

        for(int j = 0; j < i; j++){
            //printf("j : %d", j);
            if(str[i] == str[j]){
                appears = true;
                break;
            }
        }
        //printf(" - i : %d", i);
        if(!appears){
            count++;
        }
    }
    return count;
}

int main(){
    int N;
    scanf("%d", &N);

    char notes[N];
    if(N > 0)
        scanf("%s", notes);
    else
        {
            printf("0");
            return 0;
        }
    int num = distinct(notes);
    printf("%d", num);
    return 0;
}