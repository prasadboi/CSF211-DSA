#include <stdio.h>

void main(){
    int num, win,lose, ans1=0, ans2=0;
    
    scanf("%d", &num);
    int ex = num*(num-1)/2;
    int frequencyArray[num+1];
    int wins[num+1];

    for(int i = 0; i <= num; i++){
        wins[i] = 0;
        frequencyArray[i] = 0;
    }

    for(int i = 0; i < ex -1; i++){
        scanf("%d %d", &win,&lose);
        frequencyArray[win] += 1;
        frequencyArray[lose] += 1;
        wins[win] += 1;
    }

    for(int i  = 1; i <=num; i++){

        if(frequencyArray[i] == (num-2)){
            if(ans1 == 0)
                ans1 = i;
            else
                ans2 = i;
        }
    }

    if(wins[ans1] >= wins[ans2]){
        printf("%d %d", ans1, ans2);
    }
    else
        printf("%d %d", ans2, ans1);
}