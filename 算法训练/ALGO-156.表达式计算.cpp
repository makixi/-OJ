#include<iostream>
using namespace std;
int expression_value();
int term_value();
int factor_value();

int factor_value(){// 		() and digit
	int value=0;
	char c=cin.peek();
	if(c=='('){
		cin.get();
		value=expression_value();
		cin.get();
	}else{
		while(isdigit(c)){
			value=value*10+(c-'0');
			cin.get();
			c=cin.peek();
		}
	}
	return value;
}

int term_value(){	// 		* and /
	int value=factor_value();
	while(true){
		char op=cin.peek();
		if(op=='*'||op=='/'){
			cin.get();
			int tmp=factor_value();
			if(op=='*')value*=tmp;
			else value/=tmp;
		}else break;
	}
	return value;
}

int expression_value(){	// 		+ and -
	int value=term_value();
	while(true){
		char op=cin.peek();
		if(op=='+'||op=='-'){
			cin.get();
			int tmp=term_value();
			if(op=='+')value+=tmp;
			else value-=tmp;
		}else break;
	}
	return value;
}

int main(){
	ios::sync_with_stdio(false);
	cout<<expression_value()<<endl;
	return 0;
}
