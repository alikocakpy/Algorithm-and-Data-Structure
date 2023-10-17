#include <stdio.h>
#include <stdlib.h>
#include "header.h"



void DFS(int u,int A[][8],int n){
	int visited[8]={0};
	create(n);
	push(u);
	printf("%d ",u);
	visited[u]=1;
	int v=0;
	
	while (!stkEmpty()){
        while (v < n){
            if (A[u][v] == 1 && visited[v] == 0){
                 
                u = v;  
				push(u);
                
                printf("%d ",u);
                visited[u] = 1;
                v = -1; 
            }
            v++;
        }
        v = u;  
        u = stTop(); 
        pop();
    }
	
}



int main(int argc, char *argv[]) {
	
	int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
	DFS(5,A,8);
	
	return 0;
}
