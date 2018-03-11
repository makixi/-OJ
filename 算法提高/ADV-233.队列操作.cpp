#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string> 
#include<map>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int> q;
    while(n--){
    	int op;
    	cin>>op;
    	if(op==1){
    		int num;
    		cin>>num;
    		q.push(num);
		}else if(op==2){
			if(q.empty()){
				cout<<"no\n";
				break;
			}else{
				cout<<q.front()<<endl;
				q.pop();
			}
		}else cout<<q.size()<<endl;
	}
    return 0;
}
