#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int main(){
	int n,L,R,sum=0,a[99999];  
	scanf("%d",&n);  
    for(int i=0; i<n; i++)  scanf("%d",&a[i]);  
    for(int i=0; i<n; i++)  {  
        sum++;  
        L=a[i];  R=a[i];  
        for(int j=i+1; j<n; j++)  {  
            if(a[j]>R)  R=a[j];  
            if(a[j]<L)  L=a[j];  
            if(R-L==j-i)  sum++;  
        }  
    }  
    printf("%d\n",sum);  
    return 0;
}
