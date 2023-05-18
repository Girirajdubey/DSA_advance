#include<stdio.h>

struct vertex_weight{
    int u;
    int v;
    int weight;
};
struct vertex_weight node[6]={{0,0,0},{1,2,1},{2,3,2},{3,4,4},{4,5,3},{0,0,0}};
int   vertex=4;
int arr[6]={9999,9999,9999,9999,9999,9999};
void bollman_forge(int s){

    int edge= vertex-1;
    arr[s]=0; // {9999,0,9999,9999,9999}(1--2 , 2---3 , 3--4 ,4--1)

    

    int i,j;
    for(i=1 ; i<= edge ;i++){
        for(j=1 ;node[j].weight!=0;j++){
            if( arr[node[j].u] + node[j].weight <arr[node[j].v] ){
                arr[node[j].v]=arr[node[j].u] + node[j].weight;
                printf("5\n");
            }

        }

    }
    

}

int main(){
    int i =0;
    //printf("%d\t%d\t%d",node[i].u,node[i].v,node[i].weight);
    bollman_forge(1);
    for(int j=1 ; j<=sizeof(arr)/sizeof(int) ; j++){
        printf("%c -- %d" , 'A'+j , arr[j]);
        printf("\n");
    }
    

return 0;






}