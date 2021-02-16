#include <stdio.h>
#include <stdlib.h>


//int mess[5000];


void seat_fill(int *occupants, int *max)
{
    int incoming = 0, outgoing = 0;
    int *seats_free;
    char c;

    if(scanf("E %d%c", &incoming, &c))
    {
        *occupants = *occupants + incoming;
        
        //printf("current occupants : %d\n", *occupants);
    }
    else if(scanf("L %d%c", &outgoing, &c))
    {
        seats_free = malloc(outgoing * sizeof(int));
        for (int i = 0; i < outgoing; i++)
        {
            scanf("%d%c", &seats_free[i], &c);
            //mess[seats_free[i] - 1] = 0;
        }
        *occupants = *occupants - outgoing;
        //printf("current occupants : %d\n", *occupants);
    }

    if(*max < *occupants)
    {
        *max = *occupants;
    }
}

int main(int argc, char const *argv[])
{
    int occupants = 0, max_occ = 0;
    int no_args = 0;
    char c;
    scanf("%d%c", &no_args, &c);
    for (int i = 0; i < no_args; i++)
    {
        seat_fill(&occupants, &max_occ);
    }

    /*for (int i = 0; i < max_occ; i++)
    {
        printf("%d", mess[max_occ]);
    }*/
    printf("%d", max_occ);
    return 0;

}
