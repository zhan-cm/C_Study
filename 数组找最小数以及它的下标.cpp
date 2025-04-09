#include<stdio.h>
#define MAXN 10
int main(void)
{
	int i,index,n;
	static int a[MAXN];
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter %d integers:",n);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	index=0;
	for(i=1;i<n;i++){
		if(a[i]<a[index]){
			index=i;
		}
	}
	printf("min is %d\tsub is %d\n",a[index],index);
	return 0;
}
