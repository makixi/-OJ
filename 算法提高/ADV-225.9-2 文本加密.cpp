#include<stdio.h>
int main(){
	char a[51];
	int i;
	gets(a);
	for (i=0;a[i];i++){
		if (a[i]>='A'&&a[i]<'Z')a[i]=a[i]+1;
		else if (a[i]=='Z')a[i]='a';
		else if (a[i]>='a'&&a[i]<'z')a[i]=a[i]+1;
		else if (a[i]=='z')a[i]='A';
	}
	a[i]='\0';
	puts(a);
	return 0;
}
