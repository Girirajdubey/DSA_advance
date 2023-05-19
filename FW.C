#include <stdio.h>
#include <stdio.h>
#define MAX 5

int num;
int A0[MAX][MAX];
int john_wick[MAX][MAX];

void scan_data()
{
    FILE *fptr;
    fptr = fopen("graph_fw.txt", "r");
    if (fptr == NULL)
    {
        printf("\n FILE OPENING ERROR");
        return;
    }

    int i, j;
    for (i = 1; i < MAX; i++)
        for (j = 1; j < MAX; j++)
            fscanf(fptr, "%d", &A0[i][j]);
}

void Print_array(int A[][MAX])
{
    for (int i = 1; i < MAX; i++)
    {
        for (int z = 1; z < MAX; z++)
        { 
            printf("%3d", A[i][z]);
        }
        printf("\n");
    }
}
void FW()
{

    for (int x = 1; x < MAX; x++)
    {
        for (int y = 1; y < MAX; y++)
        {
            john_wick[x][y] = A0[x][y]; // coppying data;
        }
    }
    printf("\n this is john wick");

    printf("\n");

    for (int k = 1; k < MAX; k++)
    {
        for (int i = 1; i < MAX; i++)
        {
            for (int j = 1; j < MAX; j++)
            {
                if (john_wick[i][k] + john_wick[k][j] < john_wick[i][j]) // store the mean 
                    john_wick[i][j] = john_wick[i][k] + john_wick[k][j];
            }
        }
    }
}

int main()
{
    scan_data();
    FW();
    Print_array(john_wick);
    printf("\n Now , i am thinking i am back !!");
    return 0;
}