#include<stdio.h>


int main(){
    int arr[]={9,2,5,1,10,99,22,3,30,11,55};
    int n= (sizeof(arr)/sizeof(int));

    for(int i= 0 ; i< n ; i++){
            for(int j= i ; j<n ; j++){
                if(arr[i]<arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
    }
    for(int i = 0 ; i<n ; i++){
        printf("%5d",*(arr+i));

    }
}