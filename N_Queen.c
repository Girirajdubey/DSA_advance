#include<stdio.h>
#include<stdbool.h>
#define MAX 8

void print_board(int board[][MAX]){
    printf("\n\n");
    for(int i= 0 ; i<MAX ; i++){
        for(int j= 0 ; j < MAX ;j++){
            if(board[i][j]==1)
                printf(" Q ");
            else
                printf(" 0 ");
        }
        printf("\n");
    }
    printf("\n\n");

}


bool isSafe(int board[][MAX],int row , int col){
    int i,j;
    for( i = 0 ; i<= col ; i++ ){
        if(board[row][i]==1)   // colum wise checking
            return false;
    }
    
    for( i = row , j= col ;i>=0 && j>=0 ; i--,j-- ){ //for upper corner 
        if(board[i][j])
            return false ;
    }
    for( i=  row , j = col ;i<MAX && j>=0 ;i++,j--){
        if(board[i][j])
            return false ;
    
    return true ; // possible for move;
    }








}
bool Solve_NQueen(int board[][MAX],int col){
    if (col>=MAX)
        return  true ;  // base condition of  RECURSION PROBLEM
    int i ;
    for(i=0 ; i<MAX ; i++){   // i is row 
        if(isSafe(board,i,col)){
            board[i][col]=1; // [placing ]
           // print_board(board); 
            if(Solve_NQueen(board,col+1))
                return true;  // if this istrue then rest of the part will not executed 
            board[i][col]=0;    // back track   
            
        }

    }
    
    return false;


}

int main(){
    int board[MAX][MAX];
    for(int i= 0 ; i<MAX ; i++){
        for(int j= 0 ; j < MAX ;j++){
            board[i][j]=0;
        }
    }
    Solve_NQueen(board,0);
    print_board(board);



}