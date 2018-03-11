#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
typedef long long ll;

int main(){
	int n;
	cin>>hex>>n;
	cout<<"Hex: 0x"<<setw(3)<<setfill('0')<<setiosflags(ios::uppercase)<<hex<<n<<"\n";
	cout<<"Decimal: "<<dec<<n<<"\n";
	cout<<"Octal: "<<setw(4)<<setfill('0')<<oct<<n<<"\n";
	return 0;
}
