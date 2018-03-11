#include <stdio.h>
int main(){
	int i;
	char a[100],b[100];
	gets(a);
	gets(b);
	for (i=0;;i++){
		if (a[i]<b[i]){printf("-1");break;}
		if (a[i]>b[i]){printf("1");break;}
	    if (a[i]==b[i]){
			if (a[i+1]=='\0'&&b[i+1]=='\0'){printf("0");break;}
	    	if (a[i+1]=='\0'){printf("-1");break;}
	    	if (b[i+1]=='\0'){printf("1");break;}
	    }
	}
    return 0;
}
