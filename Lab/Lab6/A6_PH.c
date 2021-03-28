#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

void subArrReverse(char A[], int start, int end)
{
    char temp[10000];
    for (int i = start+1, j = 0; i < end; i++, j++)
    {
        temp[j] = A[i];
    }
    for (int i = end - 1, j = 0; i > start; i--, j++)
    {
        A[i] = temp[j];
    }
}


void incrementArrChars(char A[], int start, int end)
{
    for (int i = start+1; i < end; i++)
    {
        if(A[i] != '_')
        {
            A[i] = A[i] + 1;
            if(A[i] > 'z')
                A[i] = 'a'; 
        }
    }
}

void performOperation(char A[], int length)
{
    int start, end;
    for (int i = length - 1; i >= 0; i--)
    {
        if(A[i] == '[')
        {
            start = i;
            int j;
            for (j = i+1; A[j] != ']'; j++);
            A[i] = '_';
            A[j] = '_';
            end = j;
            incrementArrChars(A, start, end);
        }
        else if(A[i] == '(')
        {
            start = i;
            int j;
            for (j = i+1; A[j] != ')'; j++);
            A[i] = '_';
            A[j] = '_';
            end = j;
            subArrReverse(A, start, end);
        }
    }
}

void main()
{
    /*char string[100] = "ar(jun)";
    subArrReverse(string, 2, 6);
    printf("%s\n", string);
    char string2[100] = "ar[juz]";
    incrementArrChars(string2, 2, 6);
    printf("%s\n", string2);*/
    char string3[10000];
    scanf("%s", string3);
    int length = 0;
    for (int i = 0; string3[i] != '\0'; i++)
    {
        length++;
    }
    performOperation(string3, length);
    for(int i = 0; string3[i] != '\0'; i++)
    {
        if(string3[i] != '_')
            printf("%c", string3[i]);
    }
}