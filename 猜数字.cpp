#include<stdio.h>
int main(void)
{
	int i=1;
	int guess,real=66;
	printf("����ҵ�������ʲô:"); 
	scanf("%d",&guess);
	while(i!=3)
	{
		if(guess<real){
			printf("С�ˣ��ʱʣ�����\n");
		}else if(guess>real){
			printf("���ˣ��ʱʣ�����\n");
		}else{
			printf("����ţ");break; 
		}
		printf("�㻹��%d�λ���\n",3-i);
		scanf("%d",&guess);
		i++;
	 }
	if(i==3){
		printf("���Ǹ��ǣ��������ѽ,���ڲŲ³�����������");
	}
	
	
	
	return 0;
 } 
