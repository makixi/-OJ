#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){return fabs(a)<fabs(b);}
int main(){
	int n,a[51],i,j,t,c,s=1,flag=0;
	cin>>n;
	for (i=0;i<n;i++)cin>>a[i];
	c=a[0];  //c��¼��ð������ 
	sort(a,a+n,cmp);
	for (i=0;i<n;i++)
		if (a[i]==c){
			c=i;   //c����������¼��һ����ð���ϵ��±� 
			break;
		}
	for (i=0;i<c;i++)//�ų�����ߵ� 
		if (a[i]>0) break; //˵���������ƶ�
		else a[i]=0;
	for (i=n-1;i>c;i++)//�ų����ұߵ�
		if (a[i]<0)break;//˵���������ƶ�
		else a[i]=0;
	if (a[c]<0){//˵����ֻ��ð����������˵��ߵ� 
		for (i=c-1;i>=0;i--){
			if (a[i]==0) break;
			if (a[i]>0){//���������ߵĶ������Ⱦ�� 
			   s++;
			   flag=1;
			} 
		}
		if (flag)//˵�����������ߵ������б���Ⱦ�ģ������ұ�Ϯ�� 
			for(i=c+1;i<n;i++){
				if (a[i]==0)break;
				if (a[i]<0)s++;//��������ϻᱻ��Ⱦ 
	   		} 
	}
	else{//��ð�����������ߵ� 
		for (i=c+1;i<n;i++){
			if (a[i]==0)break;
			if (a[i]<0){//�����ߵ� �϶���͸�ð�������� 
			 	s++;
			 	flag=1;
			}
		}
	   if (flag)//˵�������ߵı���ð�� 
	   		for(i=c-1;i>=0;i--){//��ߵ�  
	       		if (a[i]==0)break;
		   		if (a[i]>0)s++; //�����ߵľ��군��	
	   		} 
	}
	cout<<s;
	return 0;
}
