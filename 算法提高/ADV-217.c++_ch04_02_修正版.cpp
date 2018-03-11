#include<iostream>
using namespace std;
class Time{
public:
	Time(int n_hour,int n_minute,int n_second);
	void print();
	void adv(int n_hour,int n_minute,int n_second);
	void reset();
private:
	int hour, minute, second;// 请补充
};
Time::Time(int n_hour,int n_minute,int n_second){//构造函数
	hour=n_hour; minute=n_minute; second=n_second;
}
void Time::print(){//输出函数
	if(second>=60||second<0){
		if(second>=60) minute+=(second/60),second%=60;
		else{
			int cnt=0;
			while(second<0)cnt++,second+=60;
			minute-=cnt;second%=60;
		}	
	}
	if(minute>=60||minute<0){
		if(minute>=60) hour+=(minute/60),minute%=60;
		else{
			int cnt=0;
			while(minute<0)cnt++,minute+=60;
			hour-=cnt;minute%=60;
		}
	}
	if(hour>=24||hour<0){
		if(hour>=24) hour%=24;
		else{
			while(hour<0)hour+=24;
			hour%=24;
		}
	}
	printf("%02d:%02d:%02d\n",hour,minute,second);
}
void Time::adv(int n_hour,int n_minute,int n_second){//推进当前时间
	hour+=n_hour;minute+=n_minute;second+=n_second;
}
void Time::reset(){//重置函数
	hour=0;minute=0;second=0;
}
int main(){
	// 当前时间
	int hour, minute, second;
	// 时间增量
	int incr_hr, incr_min, incr_sec;
	cin >> hour >> minute >> second >> incr_hr >> incr_min >> incr_sec;
	Time t( hour,minute,second );
	t.print();
	t.adv(incr_hr,incr_min,incr_sec);
	t.print();
	t.reset();
	t.print();
	return 0;
}
