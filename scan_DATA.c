#include<stdio.h>
#define MAX 5;
int A0[5][5];

void scan_data()
{
    FILE *fptr;
    fptr = fopen("graph_fw.txt", "r");  // FILE  *pointer_name= fopen("text name ","mode of accesing");
    if (fptr == NULL)
    {
        printf("\n FILE OPENING ERROR");
        return;
    }
    int n;
    fscanf(fptr , "%d", &n);             // fscanf( pointer_name , "format_specifiers ", &var_name);
    int i, j;
    for (i = 1; i < n; i++)
        for (j = 1; j < n; j++)
            fscanf(fptr, "%d", &A0[i][j]);
}
int main(){
    scan_data();




    return 0;
}