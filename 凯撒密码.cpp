#include<stdio.h>
# define MAXLINE 80
# define M 26
int main(void){
	int a[MAXLINE];
	int i,offset;
	
	//ÊäÈë×Ö·û´®
	printf("Enter a string:");
	i=0;
	while((a[i]=getchar())!='\n'){
		i++;
	}
	a[i]='\0';
	printf("Enter offset:");
	scanf("%d",&offset);
	if(offset>M){
		offset%=M;
	}
	//¼ÓÃÜ
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='A'&&a[i]<='Z'){
			if(a[i]-'A'+offset<M){
				a[i]=a[i]+offset;
			}else{
				a[i]=a[i]+offset-M;
			}
		}else if(a[i]>='a'&&a[i]<='z'){
			if(a[i]-'a'+offset<M){
				a[i]=a[i]+offset;
			}else{
				a[i]=a[i]+offset-M;
			}
		}
	}
	
	//Êä³ö
	for(i=0;a[i]!='\0';i++){
		putchar(a[i]);
	}
	return 0;
}
