#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node{
   int id,value;
}data;
bool compare(node a,node b){
   return a.value<b.value;
}
int main(){
   data a[1024];
   int w,n,sum=0;
   bool flag=true;
   cin>>n>>w;
   for(int i=0;i<n;++i){
       cin>>a[i].value;
       a[i].id=i+1;
       sum+=a[i].value;
    }
   if(sum<w || w<=0)cout<<"No"<<endl;
   else{
       sort(a,a+n,compare);
       if(a[0].value<=w){
           cout<<"Yes"<<endl;
           int rest=sum-w;
           cout<<a[0].id;
           int i=n-1;
           while(i>=0 && rest>=a[i].value){
                for(int j=0;j<a[i].value;++j)cout<<' '<<a[i].id<<' '<<a[i].id;
                rest-=a[i].value;
                i--;
           }
           for(int j=0;j<rest;++j)cout<<' '<<a[i].id<<' '<<a[i].id;
           cout<<' '<<a[0].id;
           a[0].value-=1;
           a[i].value-=rest;
           for(int j=0;j<=i;++j){
                for(int k=0;k<a[j].value;++k)cout<<' '<<a[j].id<<' '<<a[j].id;
           }
       }
        else if(n==1 || w==1)cout<<"No"<<endl;
       else{
           cout<<"Yes"<<endl;
           cout<<a[1].id;
           for(int j=0;j<a[0].value-1;++j)cout<<' '<<a[0].id<<' '<<a[0].id;
           cout<<' '<<a[1].id;
           for(int j=0;j<w-2;++j)cout<<' '<<a[1].id<<' '<<a[1].id;
           cout<<' '<<a[0].id;
           a[1].value=a[1].value-w+1;
           for(int i=1;i<n;++i)
                for(int j=0;j<a[i].value;++j)cout<<' '<<a[i].id<<' '<<a[i].id;
           cout<<' '<<a[0].id;
       }
    }
   return 0;
}
