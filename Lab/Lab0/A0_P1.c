#include <stdio.h>

int main()
{
    char longIntA[1000], longIntB[1000], sum[1000];
    
    // taking input values
    scanf("%s", longIntA);
    scanf("%s", longIntB);
    
    // calculating length of integers
    int lenA = 0, lenB = 0, lenSum = 0;
    for(lenA = 0; longIntA[lenA] != '\0'; lenA++);
    //printf("lenA : %d\n", lenA);
    for(lenB = 0; longIntB[lenB] != '\0'; lenB++);
    //printf("lenB : %d\n", lenB);

    if(lenA > lenB){
        int j = 0;
        while(longIntA[j] != '\0'){
            char temp;
            temp = longIntA[j];
            longIntA[j] = longIntB[j];
            longIntB[j] = temp;
            j++;
        }
        int temp = lenA;
        lenA = lenB;
        lenB = temp;
    }

    // fliping the arrays
    for(int i = 0; i < lenA/2; i++)
    {
        char temp = longIntA[i];
        longIntA[i] = longIntA[lenA - 1 - i];
        longIntA[lenA - 1 - i] = temp;
    }
    for(int i = 0; i < lenB/2; i++)
    {
        char temp = longIntB[i];
        longIntB[i] = longIntB[lenB - 1 - i];
        longIntB[lenB - 1 - i] = temp;
    }
    
    // carrying out sum process but in reverse fashion
    // we are given before hand that as per input lenA <= lenB
    int s = 0;
    int c = 0;
    for(int i = 0; i < lenA; i++)
    {
        s = (longIntA[i] - '0') + (longIntB[i] - '0') + c;
        if (s > 9)
        {
            s = s%10;
            c = 1;
        }
        else
        {
            c = 0;
        }
        sum[i] = (char)(s + '0');
    }
    for (int i = lenA; i < lenB; i++)
    {
        s = (longIntB[i] - '0') + c;
        if (s > 9)
        {
            s = s%10;
            c = 1;
        }
        else
        {
            c = 0;
        }
        sum[i] = (char)(s + '0');
    }

    if (c == 1)
    {
        sum[lenB] = (char)(c + '0');
        sum[lenB + 1] = '\0';
    }
    else
    {
        sum[lenB] = '\0';
    }
    
    
    // flipping sum back to proper form
    for(lenSum = 0; sum[lenSum] != '\0'; lenSum++);
    //printf("lenSum : %d\n", lenSum);
    for(int i = 0; i < lenSum/2; i++)
    {
        char temp = sum[i];
        sum[i] = sum[lenSum - 1 - i];
        sum[lenSum - 1 - i] = temp;
    }

    printf("%s", sum);
    return 0;
}