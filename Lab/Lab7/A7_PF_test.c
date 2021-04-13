#include <stdio.h>
#include<string.h>


struct node
{
    char str[10];
};

// function to calculate the length of a given string 
int len(char arr[]);



int main()
{
    //int num_tests;
    //scanf("%d", &num_tests);
    //for (int nt = 0; nt < num_tests; nt++)
    //{
    int num_tries;
    int k = 0;
    int flag=0;

    scanf("%d",&num_tries);
        
    struct node arr[num_tries];

    for(int i=0;i<num_tries;i++)
    {
        scanf("%s ",arr[i].str);

        if(i!=0 && k==0)
        {
            if(arr[i].str[0]!=arr[i-1].str[len(arr[i-1].str)-1])
            {
                k=i;
            }
        }
        flag = i;

    }  
        
    int y = 0;  

    for(int i=1; i<num_tries; i++)
    {
        for(int x =i-1; x>=0; x--)
        {
            if(strcmp(arr[i].str,arr[x].str)==0)
            {
               y=i; 
               break;
            }
        }

        if(y != 0 )
            break;
    }

    // printing the o/p as per situation
    if((k==0 &&  y !=0)||(( y != 0 && k != 0)&& (y < k)))
    {
        if( y%2==0 )
            printf("Bob");
        else
            printf("Alice");
    }


    else if(( y==0 && k!=0)||(( y!=0 && k!=0 )&& (k < y) ))
    {
        if(k%2==0)
            printf("Bob");
        else
            printf("Alice");
    }
    
    else 
    {
        if((flag%2)==0)
            printf("Alice");
        else 
        {
            printf("Bob");
        }
    }

    //}
    
    return 0;
}

int len(char arr[])
{
    int len;
    for(len=0;arr[len]!='\0'; len++);
    return len;
}
