#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
const double eps = 1e-8;

int main(){
	int res=0,k=0;
	bool flag=true;
    string st,des;
    cin>>st>>des;
    for(int i=0;i<st.length();++i){
    	if(st[i]!=des[i]){
    		if(flag){
    			k=i;
    			flag=false;
			}else{
				res+=i-k;
				flag=true;
			}
		}
	}
	cout<<res;
    return 0;
}
