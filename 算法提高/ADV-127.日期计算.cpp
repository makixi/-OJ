#include<iostream>
using namespace std;
int weekday(int year,int month,int day){
	int tm = month>=3 ? (month-2) : (month+10);
	int ty = month>=3 ? year : (year-1);
	return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+day)%7;
}
int main(){
	int year,month,day;
	cin>>year>>month>>day;
	int res=weekday(year,month,day);
	if(res==0)cout<<7;
	else cout<<res;
	return 0;
}
