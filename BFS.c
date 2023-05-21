#include<stdio.h>
int adj_matrix[5][5];
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
    for(i=1 ; i<= num ;i++)
        for(j=1 ; j<=num ;j++)
            fscanf(fptr,"%d",&adj_matrix[i][j]);

}



void BFS(int s){
    int visited[5]={0,0,0,0,0}; // initialize with 0
    int queue[5]  ;  //this queue for bfs
    int front = 1;
    int rear= 1;
    //make a curent node visite which is s var 
    visited[s]=1; // here 1 means visited
    queue[rear++]=s;
    while(front != rear){
        s=queue[front++];
        printf("%3c",s+'A');
        int n=1;
        while(n<5){
            if(adj_matrix[s][n] && !visited[n]){
                queue[rear++]=n;//engue in queue
                visited[n]=1;                  // visited 
            }
            n++;
        }
    }

}

int main(){

    int i ;
    scan_data();// 1 
    for(int i= 1 ;i<=num;i++){
        for(int j = 1 ;j<=num; j++){
            printf("%3d",adj_matrix[i][j]);
        }
        printf("\n");
    }
    BFS(2);



    return 0;

}
