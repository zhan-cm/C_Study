#include<stdio.h>

int main()
{
	/*     for和while的区别：
	   for循环中：知道循环次数或者循环范围
	   while循环：不知道循环的次数和范围，只知道循环的结束条件。

	   举例：累加求和1-100   for
	   举例：循环你读取文件中的内容    for  while
	          一次只能读取一个字母或者是汉字

			  while(){}
	*/



	for (int i = 1; i <= 100; i++)
	{
		printf("%d\n", i);
	}



	int i = 1;
	while (i <= 100)
	{
		printf("%d\n", i);
		i++;
	}











	return 0;
}