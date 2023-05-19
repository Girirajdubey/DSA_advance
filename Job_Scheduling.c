//job Scheduling using Greedy Algorithm
#include <stdio.h>
#include <stdlib.h>

struct temp
{
    int id;
    int profit;
    int deadline;
};
typedef struct temp JOB;
JOB array[100];
int num;

void JBS_SOLVE()
{
    // first sort this as a dead line
    int Total_profit = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (array[i].deadline <= array[j].deadline)
            {
                JOB temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    int max = array[0].deadline;
    int sol[max + 1];
    int idd[max + 1];
    // sorting as greedy algo
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (array[i].profit < array[j].profit)
            {
                JOB temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        printf("%c --- %d --- %d", 'A' + i, array[i].profit, array[i].deadline);
        printf("\n");
    }
    printf("\n entering fun ");
    // after sorting create  a sol array ;

    for (int i = 0; i <= max + 1; i++)
    {
        sol[i] = 0;
    }

    for (int i = 0; i < num; i++)
    {
        for (int k = array[i].deadline; k > 0; k--)
        {
            if (sol[k] == 0)
            {
                sol[k] = 1;
                idd[k] = array[i].id;
                Total_profit = Total_profit + array[i].profit;
                break;
            }
        }
    }
    printf(" \nname --- profit --- dead line \n ");
    for (int i = 0; i <= max; i++)
    {
        printf("%c---- id %d  --- %d --- %d", 'A' + sol[i], array[sol[i]].id, array[sol[i]].profit, array[sol[i]].deadline);
        // Total_profit=Total_profit+array[sol[i]].profit;
        printf("\n");
    }
    printf("\n  TOTAL GROSSS PROFT  IS %d\n", Total_profit);
    for (int i = 0; i <= max; i++)
    {
        printf("%3d", idd[i]);
    }
}

int main()
{
    int choice1;
    int choice2;
    while (1)
    {
        printf("\n 1  for run JBS program  ");
        printf("\n 0 RESET  all data  ");
        printf("\nEnter your choice");
        scanf("%d", &choice1);
        if (choice1 == 0)
        {
            num = 0;
            for (int i = 0; i < 100; i++)
            {
                array[i].deadline = 0;
                array[i].id = 0;
                array[i].profit = 0;
            }

            printf("\n reseting is complete");
        }
        else
        {
            printf("\n------------------");
            printf("\n Enter no of job ");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                printf("\nfor JOB %c ", 'A' + i);
                printf("\n Enter the profit for %c  ==  ", 'A' + i);
                scanf("%d", &array[i].profit);
                printf("\n Enter the DEAD LINE for %c  ==  ", 'A' + i);
                scanf("%d", &array[i].deadline);
                array[i].id = i;
            }
            printf("\n data collecting complete");
            JBS_SOLVE();
        }
    }

    return 0;
}