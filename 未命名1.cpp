#include<stdio.h>
int main(void)
{
	int a=0,b=0;
	printf("�������������֣�");
	scanf("%d%d",&a,&b);
	if(a>=b){
		int i=0;
		for(i=b;i>=1;i--){
			if(a%i==0&&b%i==0){
				printf("���Լ����%d",i);
				break;
			}
		}
	}
	else{
		int j=0;
		for(j=a;j>=1;j--){
			if(a%j==0&&b%j==0){
				printf("���Լ����%d",j);
				break;
			}
		}
	}
	return 0;
}
