#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int n;
double r;
double res=0;
void solve(double x1,double y1,double x2,double y2,double x3,double y3){
	double cy=(y1+y3)/2,dl;
	double flagy=cy-y2;//<0Í¹ >0°¼
	double mx = x2 -x1,my = y2 -y1,nx = x2 -x3,ny = y2 -y3;  
    double m = sqrt(mx*mx+my*my),n = sqrt(nx*nx+ny*ny);
	res+=n; 
    double angle = acos((mx*nx+my*ny)/(m*n));  
    if(flagy>0)  {  
        dl = 2*r/tan(angle/2);  
        res -= dl;  
    }pelse{  
        angle = pi - angle;  
        dl = r*angle;  
        res += dl;  
    }  
}
int main(){
	ios::sync_with_stdio(false); 
	cin>>n>>r;
	vector<pair<double,double> > d(n);
	for(int i=0;i<n;++i)cin>>d[i].first>>d[i].second;
	res+=sqrt((d[1].first-d[0].first)*(d[1].first-d[0].first)+(d[1].second-d[0].second)*(d[1].second-d[0].second));
	for(int i=1;i<n-1;++i)
		solve(d[i-1].first,d[i-1].second,d[i].first,d[i].second,d[i+1].first,d[i+1].second);
	printf("%.2lf",res);
	return 0;
}
