#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
string str="ABCDE";
string init="ABCDE";
string ss[5];
int cnt=0;
map<char,int> mm;
void solve(){
	bool flag=true;
	bool lie=false;
	int tmp;
	for(int i=0;i<5;++i){
		if(!flag)return;
		int trueRank=mm[ss[i][0]];
		int giveRank=ss[i][ss[i].length()-1]-'0';
		string op=ss[i].substr(1,ss[i].length()-2);
		tmp=mm[init[i]];
		lie=tmp&1?true:false;
		if(op=="<"){
			if(lie){if(trueRank<giveRank)flag=false;
			}else{if(trueRank>=giveRank)flag=false;}
		}else if(op=="<="){
			if(lie){if(trueRank<=giveRank)flag=false;
			}else{if(trueRank>giveRank)flag=false;}
		}else if(op=="="){
			if(lie){if(trueRank==giveRank)flag=false;
			}else{if(trueRank!=giveRank)flag=false;}
		}else if(op==">="){
			if(lie){if(trueRank>=giveRank)flag=false;}
			else{if(trueRank<giveRank)flag=false;}
		}else if(op==">"){
			if(lie){if(trueRank>giveRank)flag=false;}
			else{if(trueRank<=giveRank)flag=false;}
		}else if(op=="!="){
			if(lie){if(trueRank!=giveRank)flag=false;}
			else{if(trueRank==giveRank)flag=false;}
		}
	}
	if(flag){
		cout<<str<<"\n";
		++cnt;
	}
}
int main(){
	for(int i=0;i<5;++i)cin>>ss[i];
	do{
		for(int i=0;i<5;++i)mm[str[i]]=i+1;
		solve();
	}while(next_permutation(str.begin(),str.end()));
	cout<<cnt;
	return 0;
}
