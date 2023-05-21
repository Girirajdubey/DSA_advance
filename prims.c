#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 999999
#define V 5
int G[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}};

    int main(){
        int no_edges = 0;
bool Selected[V];
for (int i = 0; i < V; i++)
    Selected[i] = false;
Selected[0] = true;
int x;
int y;
int min;
printf("\n enter the edges");
while (no_edges < V - 1)
{
    min = INF;
    x = 0;
    y = 0;
    // time nahi hai parne k just dekho aur pratice karo
    
    for (int i = 0; i < V; i++)
    {
        if (Selected[i])
        {
            for (int j = 0; j < V; j++)
            {
                if (!Selected[j] && G[i][j])
                {
                    if (min > G[i][j])
                    {
                        min = G[i][j];
                        x = i; // assing the the vertex which is satisfy the following loop
                        y = j;
                    }
                }
            }
        }
    }
    printf("\n%d --> %d :  %d  ", x, y, G[x][y]);
    Selected[y] = true;
    no_edges++;
}
return 0;
}