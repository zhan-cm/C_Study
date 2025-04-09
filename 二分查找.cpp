#include<stdio.h>
int main(void){
	int x,n=10,mid;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	printf("Enter x:");
	scanf("%d",&x);
	int low=0,high=n-1;
	while(low<=high){
		mid = (low+high)/2;
		if(x==a[mid]){
			break;
		}else if(x<a[mid]){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	if(low<=high){
		printf("Index is %d\n",mid);
	}else{
		printf("No");
		}
	
	return 0;
}
