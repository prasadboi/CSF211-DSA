#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float manhattanDist(float P1[3], float P2[3])
{
    return (abs(P2[0] - P1[0]) + abs(P2[1] - P1[1]));
}
/*void print_arr(float arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}*/
/*void printMat2D(int n,int m, float mat[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%f ", mat[i][j]);

        }
        printf("\n");
    }
    
}*/
void insertionSort(float arr[][3], int n) 
{ 
    //printf("calling insertion sort\n");
    int i, key, key_0, key_1, j; 
    for (i = 1; i < n; i++) { 
        
        key = arr[i][2]; 
        key_0 = arr[i][0];
        key_1 = arr[i][1];
        j = i - 1; 
        while (j >= 0 && key < arr[j][2]) 
        { 
            arr[j + 1][2] = arr[j][2];
            arr[j+1][1] = arr[j][1];
            arr[j+1][0] = arr[j][0]; 
            j = j - 1; 
        } 
        arr[j+1][2] = key;
        arr[j+1][1] = key_1;
        arr[j+1][0] = key_0; 
    } 
} 

void sumManhattanDist(float P[][2], int numPoints)
{
    int sumDist = 0;
    int i,ctrPlus, ctrMinus;

    float PositiveX[numPoints][3];
    float NegativeX[numPoints][3];

    for (i = 0, ctrPlus = 0, ctrMinus = 0; i < numPoints; i++)
    {
        if(P[i][0] >= 0)
        {
            //append to postiveX
            PositiveX[ctrPlus][0] = P[i][0];
            PositiveX[ctrPlus][1] = P[i][1];
            /*if(PositiveX[ctrPlus][0] == 0 && PositiveX[ctrPlus][1] > 0)
                PositiveX[ctrPlus][2] = INFINITY;
            else if(PositiveX[ctrPlus][0] == 0 && PositiveX[ctrPlus][1] < 0)
                PositiveX[ctrPlus][2] = -1*INFINITY;
            else*/
                PositiveX[ctrPlus][2] = PositiveX[ctrPlus][1]/PositiveX[ctrPlus][0]; 
            ctrPlus++;
        }
        else if(P[i][0] < 0)
        {
            NegativeX[ctrMinus][0] = P[i][0];
            NegativeX[ctrMinus][1] = P[i][1];
            NegativeX[ctrMinus][2] = (float)(NegativeX[ctrMinus][1]/NegativeX[ctrMinus][0]);
            ctrMinus++;
        }
        }
        
        //printf("Printing PositiveX\n");
        //printMat2D(ctrPlus, 3, PositiveX);
        insertionSort(PositiveX, ctrPlus);
        //printf("Printing PositiveX\n");
        //printMat2D(ctrPlus, 3, PositiveX);

        //printf("Printing NegativeX\n");
        //printMat2D(ctrMinus, 3, NegativeX);
        insertionSort(NegativeX, ctrMinus);
        //printf("Printing NegativeX\n");
        //printMat2D(ctrMinus, 3, NegativeX);

        for (int i = 0; i < ctrPlus;i++)
        {
            P[i][0]=PositiveX[i][0];
            P[i][1]=PositiveX[i][1];
            P[i][2]=PositiveX[i][2];
        }
        for ( int i = ctrPlus; i < numPoints; i++)
        {
            P[i][0] = NegativeX[i-ctrPlus][0];
            P[i][1] = NegativeX[i - ctrPlus][1];
        }
        //printf("Printing modified P : \n"); 
        //printMat2D(numPoints, 2, P);
        for (i = 0; i < numPoints-1; i++)
        {
            sumDist += manhattanDist(P[i], P[i+1]);
        }
        if(i = numPoints-1)
            sumDist += manhattanDist(P[i], P[0]);
    printf("%d", sumDist);
    
}

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    float P[num][2];
    for (int i = 0; i < num; i++)
    {
        //printf("%d : ", i);
        scanf("%f%f", &P[i][0], &P[i][1]);
    }
    //printf("Printing P\n");
    
    //printMat2D(num, 2, P);
    sumManhattanDist(P, num);
    return 0;
}
