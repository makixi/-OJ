#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
bool num[2015];
int curr=1;
void findnext(){
	for(int i=curr+1;true;++i)
		if(!num[i]){
			curr=i;break;
		}
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		string op;
		cin>>op;
		if(op[0]=='N'){
			cout<<curr<<"\n";
			num[curr]=true;
			findnext();
		}else{
			int a;
			scanf("%d",&a);
			if(!num[a])cout<<"Failed\n";
			else{
				cout<<"Successful\n";
				num[a]=false;
				curr=min(curr,a);
			}
		}
	}
	return 0;
}
