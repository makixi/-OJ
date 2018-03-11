#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
const double pi=3.1415926;
int main(){
	double r;
	cin>>r;
	double res=4.0/3*pi*pow(r,3);
	printf("%.5lf",res);
	return 0;
}
