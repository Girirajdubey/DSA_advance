#include <stdio.h>
int num;
int sample[1000];
int max;    //global var are max and min
int min;

void maxx_min(int low, int high)
{
    int max2;
    int min2;
    if (low == high)
    {
        max = sample[high];
        min = sample[low];
        return;
    }//end of if
    else
    {
        if (low == high - 1)
        {
            if (sample[low] < sample[high])
            {
                max = sample[high];
                min = sample[low];
                return;
            }
            else
            {
                max = sample[low];
                min = sample[high];
                return;
            }
        } // end of nested if
        else
        {
            int mid = (low + high) / 2;
            maxx_min(low, mid);
            max2 = max;
            min2 = min;
            maxx_min(mid + 1, high);
            if(max<max2)
                max=max2;
            if(min>min2)
                min=min2;
        }//end of nested else 
    }//end of else 
}

int main()
{
    scanf("%d", &num);
    printf("\n");
    for (int i = 0; i < num; i++)
    {
        printf("\nEnter the element  %d \t ", i);
        scanf("%d", (sample + i));   // (sample + i ) == &sample[i];
    }
    
    maxx_min(0,num-1);
    printf("\nMAX-->%d\nMIN-->%d",max,min);
    return 0;
}
