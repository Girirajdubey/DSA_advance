#include<stdio.h>
int adj_matrix[100][100];
int visited[1000];
int num;
void scan_data(){
    FILE *fptr;
    fptr=fopen("graph.txt","r");
    if(fptr== NULL){    
        printf("\n FILE OPENING ERROR");
        return;
    }
    
    fscanf(fptr,"%d",&num);
    int i , j;
    for(i=0 ; i< num ;i++)
        for(j=0 ; j<num ;j++)
            fscanf(fptr,"%d",&adj_matrix[i][j]);

}



void DFS(int s){
     // initialize with 0
    int i ;
    visited[s]=1;
    printf("%3c",s+'A');
    for(i=0 ; i<num;i++){
        if(!visited[i] && adj_matrix[s][i])
            DFS(i);
    }

}

int main(){

    int i ;
    scan_data();// 1 
    for(i=1 ; i<=num;i++)
        visited[i]=0;
    
    //BFS(2);
    DFS(0);
    printf("\n");
    for(int i = 0 ; i< num ;i++){
        for(int j= 0 ;j <num ;j++)
            printf("%3d",adj_matrix[i][j]);
        printf("\n");
    }


    return 0;

}