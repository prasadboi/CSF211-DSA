#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float manhattanDist(float P1[4], float P2[4])
{
    return (abs(P2[1] - P1[2]) + abs(P2[2] - P1[2]));
}
void print_arr(float arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}


void printMat2D(int n,int m, float mat[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%f ", mat[i][j]);

        }
        printf("\n");
    }
    
}
void insertionSort(float arr[][4], int n) 
{ 
    //printf("calling insertion sort\n");
    float zero_arr[4] = {0, 0, 0, 0} ;
    int i, j;
    for (i = 1; i < n; i++) { 
        float key_arr[4] = {arr[i][0], arr[i][1], arr[i][2], arr[i][3]};
        
        j = i - 1; 
        while (j >= 0 && ((key_arr[3] < arr[j][3])||((key_arr[3] == arr[j][3])&&(manhattanDist(arr[j], zero_arr)  > manhattanDist(key_arr, zero_arr))))) 
        { 
            arr[j+1][3] = arr[j][3];
            arr[j+1][2] = arr[j][2];
            arr[j+1][1] = arr[j][1]; 
            arr[j+1][0] = arr[j][0];
            j = j - 1; 
        } 
        arr[j+1][3] = key_arr[3];
        arr[j+1][2] = key_arr[2];
        arr[j+1][1] = key_arr[1];
        arr[j+1][0] = key_arr[0];
    } 
} 

void destroyAVL(float P[][3], int numPoints)
{
    float All_might_y = P[0][2], All_might_x;
    for (int i = 0; i < numPoints; i++)
    {
        if(All_might_y > P[i][2])
        {
            All_might_y = P[i][2];
            All_might_x = P[i][1];
        }
    }

    //printf("All might x : %f, All might y : %f\n", All_might_x, All_might_y);
    
    int sumDist = 0;
    int i,ctrPlus, ctrMinus;

    float PositiveX[numPoints][4];
    float NegativeX[numPoints][4];

    for (i = 0, ctrPlus = 0, ctrMinus = 0; i < numPoints; i++)
    {
        if(((P[i][1] - All_might_x) >= 0)  && (P[i][2] != All_might_y))
        {
            //append to positiveX
            PositiveX[ctrPlus][0] = P[i][0];
            PositiveX[ctrPlus][1] = P[i][1] - All_might_x;
            PositiveX[ctrPlus][2] = P[i][2] - All_might_y;
            if(PositiveX[ctrPlus][1] == 0 && PositiveX[ctrPlus][2] > 0)
                PositiveX[ctrPlus][3] = INFINITY;
            else if(PositiveX[ctrPlus][1] == 0 && PositiveX[ctrPlus][2] < 0)
                PositiveX[ctrPlus][3] = -1*INFINITY;
            else
                PositiveX[ctrPlus][3] = (PositiveX[ctrPlus][2])/(PositiveX[ctrPlus][1]); 
            ctrPlus++;
        }
        else if(((P[i][1] - All_might_x) < 0) && (P[i][2] != All_might_y))
        {
            NegativeX[ctrMinus][0] = P[i][0];
            NegativeX[ctrMinus][1] = P[i][1] - All_might_x;
            NegativeX[ctrMinus][2] = P[i][2] - All_might_y;
            NegativeX[ctrMinus][3] = (float)(NegativeX[ctrMinus][2]/NegativeX[ctrMinus][1]);
            ctrMinus++;
        }
        }
        
        //printf("Printing PositiveX\n");
        //printMat2D(ctrPlus, 4, PositiveX);
        insertionSort(PositiveX, ctrPlus);
        //printf("Printing PositiveX\n");
        //printMat2D(ctrPlus, 4, PositiveX);

        //printf("Printing NegativeX\n");
        //printMat2D(ctrMinus, 4, NegativeX);
        insertionSort(NegativeX, ctrMinus);
        //printf("Printing NegativeX\n");
        //printMat2D(ctrMinus, 4, NegativeX);

        for (int i = 0; i < ctrPlus;i++)
        {
            P[i][0] = PositiveX[i][0];
            P[i][1]=PositiveX[i][1];
            P[i][2]=PositiveX[i][2];
        }
        for ( int i = ctrPlus; i < numPoints; i++)
        {
            P[i][0] = NegativeX[i - ctrPlus][0];
            P[i][1] = NegativeX[i-ctrPlus][1];
            P[i][2] = NegativeX[i - ctrPlus][2];
        }
        //printf("Printing modified P : \n"); 
        for(int i = 0; i < numPoints-2; i++)
        {
            printf("%d ", (int)P[i][0]);
        }
        printf("%d", (int)P[numPoints-2][0]);
    
}

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    float P[num][3];
    for (int i = 0; i < num; i++)
    {
        //printf("%d : ", i);
        scanf("%f%f%f", &P[i][0], &P[i][1], &P[i][2]);
    }
    //printf("Printing P\n");
    
    //printMat2D(num, 2, P);
    destroyAVL(P, num);
    return 0;
}
