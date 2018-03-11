#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.length();++i){
		if(isupper(str[i]))str[i]=tolower(str[i]);
		else if(islower(str[i]))str[i]=toupper(str[i]);
	}
	cout<<str;
	return 0;
}
