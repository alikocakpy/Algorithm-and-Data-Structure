#include <stdio.h>
#include <stdlib.h>
#define I INT_MAX
#define V 8

int prnt(int t[][V-2],int n){
	int i;
	for(i=0;i<n;i++){
 		printf("( %d , %d ) \n",t[0][i],t[1][i]);
	 }
}
//this is actually complex but almost easy algoritm but first of all you have to try to understand
//first of all we prepare gatgets. we found min value and put the its row and column value
//after that check every element who most near value neighbors after that level we prapere everything
//and the rest automatically make itself. first check next min vertex and keep its column value 
// after that all near array update who is near new new values. algorithm simple when you understand dont be afraid only focus and think.(maybe watch video about graps (abdul bari))!!!;


int PrimsMST(int a[V][V],int n){
	int u,v,i,j;
	int track[V];
	int t[2][V-2]={0};
	int min=I;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(a[i][j]<min){
				min=a[i][j];
				u=i;
				v=j;
			}
		}
	}
	track[u]=track[v]=0;
	t[0][0]=u;
	t[1][0]=v;
	
	for(i=1;i<V;i++){
		if(track[i]!=0){
			if(a[i][u]<a[i][v])
				track[i]=u;
			else{
				track[i]=v;
			}
		}
	}
		
	for(i=1;i<n-1;i++){
		int k;
		min=I;
		for(j=1;j<V;j++){
			if(track[j]!=0 && a[j][track[j]]<min){
				k=j;
				min=a[j][track[j]];
			}
		}
		t[0][i]=k;
		t[1][i]=track[k];
		track[k]=0;
		
		
		for(j=1;j<V;j++){
			if(track[j]!=0 && a[j][k]<a[j][track[j]]){
				track[j]=k;
			}
		}
	}
	prnt(t,V-2);	
}


int main(int argc, char *argv[]) {
	int cost [V][V]= {{I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
 	int n=sizeof(cost[0])/sizeof(cost[0])[0]-1;
 	PrimsMST(cost,n);
 	
 	
	return 0;
}
