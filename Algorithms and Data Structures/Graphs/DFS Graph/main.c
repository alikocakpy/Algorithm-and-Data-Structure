#include <stdio.h>
#include <stdlib.h>

void DFS(int i,int A[][8],int n){
	int v;
	static int visited[8]={0};
	if(visited[i]==0){
		printf("%d ",i);
		visited[i]=1;
		for(v=1;v<n;v++){
			if(A[i][v]==1 && visited[v]==0){
				DFS(v,A,n);
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
 
 	DFS(5,A,8);
	
	return 0;
}
