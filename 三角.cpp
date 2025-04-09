/*#include<stdio.h>
int day_of_year(int year,int month,int day)
{
	int k,leap;
	int tab[2][13]={
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31}
	};
	leap=(year%4==0&&year%100!=0||year%400==0);
	for(k=1;k<month;k++){
		day=day+tab[leap][k];
	}
	return day;
}
int main()
{
	//int n;
	//printf("Enter n:");
	//scanf("%d",&n);
	int year,month,day;
	scanf("%d %d %d",&year,&month,&day);
	day_of_year(year,month,day);
	printf("%d",day_of_year(year,month,day));
}*/
#include<stdio.h>
int main()
{
	int num,fail;
	double score,total;
	num=0;
	fail=0;
	total=0;
	printf("Enter scores:");
	scanf("%lf",&score);
	while(score>=0){
		total+=score;
		num++;
		if(score<60){
			fail++;
		}
		scanf("%lf",&score);
	}
	if(num!=0){
		printf("Average is %.2f\n",total/num);
		printf("failure is %d\n",fail);
	}else{
		printf("Wrong");
	}
	
	
	
	return 0;
}
