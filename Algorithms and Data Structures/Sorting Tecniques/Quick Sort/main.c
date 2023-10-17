#include <stdlib.h>
#include <stdio.h>

int portition(int a[],int l,int h){
	int pivot=a[l];
	int i=l,j=h,temp;
	do{
		do{
			i++;
		}while(a[i]<=pivot);
		do{
			j--;
		}while(a[j]>pivot);
		
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		
	}while(i<j);
	
	temp=a[l];
	a[l]=a[j];
	a[j]=temp;
	
	return j;
}

void quick(int a[],int l,int h){
	int j;
	if(l<h){
		j=portition(a,l,h);
		quick(a,l,j);
		quick(a,j+1,h);
	}
}



int main(){
	int a[]={5,3,9,6,4,8,0,7,2,1};
	quick(a,0,sizeof(a)/sizeof(a[0]));
	
	int i;
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	
}
