#include<stdio.h>
# define MAXN 10
void bubble (int a[],int n){
	int i,j;
	for(int i=1;i<n;i++){
		for(j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}

int main(void){
	int n,a[MAXN];
	int i;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter %d integers:",n);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	bubble(a,n);
	for(i=0;i<n;i++){
		printf("%3d",a[i]);
	}
	
	
	
	return 0;
}
