#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){return fabs(a)<fabs(b);}
int main(){
	int n,a[51],i,j,t,c,s=1,flag=0;
	cin>>n;
	for (i=0;i<n;i++)cin>>a[i];
	c=a[0];  //c记录感冒的蚂蚁 
	sort(a,a+n,cmp);
	for (i=0;i<n;i++)
		if (a[i]==c){
			c=i;   //c现在用来记录第一个感冒蚂蚁的下标 
			break;
		}
	for (i=0;i<c;i++)//排除最左边的 
		if (a[i]>0) break; //说明是向右移动
		else a[i]=0;
	for (i=n-1;i>c;i++)//排除最右边的
		if (a[i]<0)break;//说明是向左移动
		else a[i]=0;
	if (a[c]<0){//说明这只感冒蚂蚁是向左端的走的 
		for (i=c-1;i>=0;i--){
			if (a[i]==0) break;
			if (a[i]>0){//凡是向右走的都被会感染的 
			   s++;
			   flag=1;
			} 
		}
		if (flag)//说明从左向右走的蚂蚁有被感染的，正向右边袭来 
			for(i=c+1;i<n;i++){
				if (a[i]==0)break;
				if (a[i]<0)s++;//向左的蚂蚁会被感染 
	   		} 
	}
	else{//感冒蚂蚁是向右走的 
		for (i=c+1;i<n;i++){
			if (a[i]==0)break;
			if (a[i]<0){//向左走的 肯定会和感冒蚂蚁碰面 
			 	s++;
			 	flag=1;
			}
		}
	   if (flag)//说明向左走的被感冒了 
	   		for(i=c-1;i>=0;i--){//左边的  
	       		if (a[i]==0)break;
		   		if (a[i]>0)s++; //向右走的就完蛋咯	
	   		} 
	}
	cout<<s;
	return 0;
}
