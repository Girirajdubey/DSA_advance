#include <stdio.h>
#define MAX 4
int Target[MAX];
void Merge(int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = Target[low + i]; // r array low to mid
    for (int i = 0; i < n2; i++)
        R[i] = Target[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            Target[k] = L[i];
            i++;
            k++;
        }
        else
        {
            Target[k] = R[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        Target[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        Target[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int low, int high)
{ // low is 0 and high is size -1  only index
    int mid;
    if (low < high)
    { // massive base condition
        mid = (high + low) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        Merge(low, mid, high);
    }
    else
        return;
}
int main()
{
    printf("\n MERGE SORT");
    for (int i = 0; i < MAX; i++)
    {
        printf("Index { %d } ==  ", i);
        scanf("%d", &Target[i]);
    }
    
    merge_sort(0, MAX-1);
    for (int i = 0; i < MAX; i++)
        printf("%5d", Target[i]);
    

    return 0;
}