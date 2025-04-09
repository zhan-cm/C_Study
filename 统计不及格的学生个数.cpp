#include<stdio.h>
int main()
{
	int count,num;
	double score,total;
	num=0;
	total=0;
	count=0;
	printf("Enter scores:");
	scanf("%lf",&score);
	while(score>=0){
		total+=score;
		num++;
		if(score<60){
			count++;
		}
		scanf("%lf",&score);
	}
	if(num!=0){
		printf("Average is %.2f\n",total/num);
		printf("Number of failure is %d\n",count);
	}else{
		printf("Average is 0\n");
	} 
	return 0;
 } 
