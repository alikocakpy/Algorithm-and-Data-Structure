#include <stdio.h>
#include <stdlib.h>
#include "header.h"



void BFS(int i,int A[][8],int n){
	int u,v;
	create(n);
	int visited[8]={0};
	visited[i]=1;
	printf("%d ",i);
	enqueue(i);
	
	while(!isEmpty(q)){
		u=dequeue();
		for(v=0;v<=n;v++){
			if(A[u][v]==1 && visited[v]==0){
				printf("%d ",v);
				visited[v]=1;
				enqueue(v);
			}
		}
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
 
 	BFS(7,A,8);
	
	return 0;
}
