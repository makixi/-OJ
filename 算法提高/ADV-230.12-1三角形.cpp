#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define for(i,x,n) for(int i=x;i<n;i++)
#define ll long long int
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAX_N 50005
using namespace std;
struct triangle{double x,y;};
triangle a,b,c;
double perimeter(triangle a,triangle b,triangle c){
    double d1=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
    double d2=sqrt(pow(b.x-c.x,2)+pow(b.y-c.y,2));
    double d3=sqrt(pow(a.x-c.x,2)+pow(a.y-c.y,2));
    return d1+d2+d3;
}
double area(triangle a,triangle b,triangle c){
    double d1=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
    double d2=sqrt(pow(b.x-c.x,2)+pow(b.y-c.y,2));
    double d3=sqrt(pow(a.x-c.x,2)+pow(a.y-c.y,2));
    double p=(d1+d2+d3)/2;
    double area=sqrt(p*(p-d1)*(p-d2)*(p-d3));
    return area;
}
triangle external(triangle aa,triangle bb,triangle cc){
    double a=2*(aa.x-bb.x);
    double b=2*(aa.y-bb.y);
    double z=aa.x*aa.x-bb.x*bb.x+aa.y*aa.y-bb.y*bb.y;
    double a1=2*(cc.x-bb.x);
    double b1=2*(cc.y-bb.y);
    double z1=cc.x*cc.x-bb.x*bb.x+cc.y*cc.y-bb.y*bb.y;
    triangle ex;
    ex.x=((z*b1)-(z1*b))/((a*b1)-(a1*b));
    ex.y=((a*z1)-(a1*z))/((a*b1)-(a1*b));
    return ex;
}
triangle gravityOfCenter(triangle a,triangle b,triangle c){
    triangle gra;
    gra.x=(a.x+b.x+c.x)/3;
    gra.y=(a.y+b.y+c.y)/3;
    return gra;
}
int main(){
    scanf("%lf %lf",&a.x,&a.y);
    scanf("%lf %lf",&b.x,&b.y);
    scanf("%lf %lf",&c.x,&c.y);
    printf("%.2lf\n",perimeter(a,b,c));
    printf("%.2lf\n",area(a,b,c));
    printf("%.2lf %.2lf\n",external(a,b,c).x,external(a,b,c).y);
    printf("%.2lf %.2lf\n",gravityOfCenter(a,b,c).x,gravityOfCenter(a,b,c).y);
    return 0;
}
