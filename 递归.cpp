#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	int i,n=0;
	char *poem[20],str[80],mean[20];
	gets(str);
	while(str[0]!='#'){
		poem[n]=(char *)malloc(sizeof(char)*(strlen(str)+1));
		strcpy(poem[n],str);
		n++;
		gets(str);
	}
	for(i=0;i<n;i++){
		mean[i]=*poem[i];
		free(poem[i]);
	}
	mean[i]='\0';
	puts(mean);
	return 0;

}


