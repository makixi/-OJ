#include<stdio.h>
#include<string.h>
void bijiao(char str[]){
	if(strcmp(str,"*-")==0)printf("a");
	if(strcmp(str,"-***")==0)printf("b");
	if(strcmp(str,"-*-*")==0)printf("c");
	if(strcmp(str,"-**")==0)printf("d");
	if(strcmp(str,"*")==0)printf("e");
	if(strcmp(str,"**-*")==0)printf("f");
	if(strcmp(str,"--*")==0)printf("g");
	if(strcmp(str,"****")==0)printf("h");
	if(strcmp(str,"**")==0)printf("i");
	if(strcmp(str,"*---")==0)printf("j");
	if(strcmp(str,"-*-")==0)printf("k");
	if(strcmp(str,"*-**")==0)printf("l");
	if(strcmp(str,"--")==0)printf("m");
	if(strcmp(str,"-*")==0)printf("n");
	if(strcmp(str,"---")==0)printf("o");
	if(strcmp(str,"*--*")==0)printf("p");
	if(strcmp(str,"--*-")==0)printf("q");
	if(strcmp(str,"*-*")==0)printf("r");
	if(strcmp(str,"***")==0)printf("s");
	if(strcmp(str,"-")==0)printf("t");
	if(strcmp(str,"**-")==0)printf("u");
	if(strcmp(str,"***-")==0)printf("v");
	if(strcmp(str,"*--")==0)printf("w");
	if(strcmp(str,"-**-")==0)printf("x");
	if(strcmp(str,"-*--")==0)printf("y");
	if(strcmp(str,"--**")==0)printf("z");
}
int main(){
	char arr[10000],str[10],*p;
	int i;
	while(scanf("%s",arr)!=EOF){
		p=arr;
		i=0;
		while(*p){
			if(*p=='|'){
				str[i]='\0';
				bijiao(str);
				i=0;
			}
			else str[i++]=*p;
			p++;
		}
		str[i]='\0';
		bijiao(str);
		printf("\n");
	}
	return 0;
} 
