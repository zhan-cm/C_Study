#include<stdio.h>
int main()
{
	int number,sum=0;
	printf("Enter number:");
	while(1){
		scanf("%d",&number);
		if(number<=0){break;}
		if(number%2!=0)
		{
			sum+=number;
		} 
	}
	printf("sum is %d",sum);
	return 0;
 } 
