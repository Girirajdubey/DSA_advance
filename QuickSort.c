#include <stdio.h>
#include<stdlib.h>
int arr[] = {9, 6, 1, 3, 5};
int size = (sizeof(arr) / sizeof(int));


void Quick_sort(int low, int high){
    if(low<high){
        int P=Partition(low,high);  // return index ;
        Quick_sort(low,P-1);
        Quick_sort(P+1,high);
    }
    
}
int  Partition(int low ,int high){
    int pivot=arr[low];
    int i=low;
    for(int j= low+1 ; j<=high ; j++){
        if(pivot>arr[j]){
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    int temp2=arr[i];
    arr[i]=arr[low];
    arr[low]=temp2;


    return i;

}


int main()
{
    Quick_sort(0,size-1);

    for(int i = 0 ; i< size ; i++)
        printf("%3d",arr[i]);

    
    return 0;
}