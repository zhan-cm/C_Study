#include<stdio.h>
int main()
{
	int n;
	double sum=0;
	printf("Enter n:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		sum+=1.0/(2*i-1);
	}
	printf("%.2lf",sum);
	
	
	return 0;
 } 
