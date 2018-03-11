#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
	char c;
	string stra,strb;
	cin>>c>>stra>>strb;
	int a=stoi(stra),b=stoi(strb);
	switch(c){
		case '+':cout<<a+b;break;
		case '-':cout<<a-b;break;
		case '*':cout<<a*b;break;
		case '/':cout<<a/b;break;
	}
	return 0;
} 
