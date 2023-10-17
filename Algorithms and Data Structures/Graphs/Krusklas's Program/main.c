#include <stdio.h>
#include <stdlib.h>
#define I INT_MAX
#define V 7
#define E 9


void Union(int u,int v,int s[]){
	if(s[u]<s[v]){
		s[u]+=s[v];
		s[v]=u;
	}
	else{
		s[v]+=s[u];
		s[u]=v;
	}
}

int find(int v,int s[]){
	int x=v;
	int u=0;
	while(s[x]>0){
		x=s[x];
	}
	while(v!=x){
		u=s[v];
		s[v]=x;
		v=u;
	}
	return x;
}

void prnt(int t[][V-1],int a[][E]){
	int i;
	for(i=0;i<V-1;i++)
		printf("[%d]-[%d] \n",t[0][i],t[1][i]);
	
}

int kruskals(int a[3][9]){
	int i,j,u,v,min,k;
	int t[2][V-1]={0};
	int track[E]={0};
	int set[V+1]={-1,-1,-1,-1,-1,-1,-1,-1};
	i=0;
	while(i<V-1){
		int min=I;
		k=v=u=0;
		for(j=0;j<E;j++){
			if(track[j]==0 && a[2][j]<min){
				min=a[2][j];
				u=a[0][j];
				v=a[1][j];
				k=j;
			}
		}
		if(find(u,set)!=find(v,set)){
			t[0][i]=u;
			t[1][i]=v;
			Union(find(u,set),find(v,set),set);
			i++;
		}
		track[k]=1;
		
	
	}
	prnt(t,a);
	
	
}


int main(int argc, char *argv[]) {
	int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
    
    kruskals(edges);
    
	return 0;
}
