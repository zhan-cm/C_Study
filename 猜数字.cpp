#include<stdio.h>
int main(void)
{
	int i=1;
	int guess,real=66;
	printf("你猜我的数字是什么:"); 
	scanf("%d",&guess);
	while(i!=3)
	{
		if(guess<real){
			printf("小了，彩笔，再来\n");
		}else if(guess>real){
			printf("大了，彩笔，再来\n");
		}else{
			printf("算你牛");break; 
		}
		printf("你还有%d次机会\n",3-i);
		scanf("%d",&guess);
		i++;
	 }
	if(i==3){
		printf("不是哥们，你是真菜呀,现在才猜出来，啧啧啧");
	}
	
	
	
	return 0;
 } 
