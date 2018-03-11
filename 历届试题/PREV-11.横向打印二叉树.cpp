#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int fir;
struct node{
	node *lchild,*rchild;
	int val;
	node(){lchild=rchild=NULL;}
};
node* insert(node *root,int val){
	if(root==NULL){
		root=new node();
		root->val=val;
	}else if(root->val>val) root->lchild=insert(root->lchild,val);
	else root->rchild=insert(root->rchild,val);
	return root;
}
void dfs(node *head,string s,int n,string s1){
	if(head->val == fir) s+=to_string(head->val);   
	else s+="-|-",s+=to_string(head->val);
	if(head->rchild!=NULL) 
		s1+="1",dfs(head->rchild,s,n+1,s1),s1 = s1.substr(0,s1.length()-1);
	int len = s.length();
	int cot = 0;
	for(int i=0;i<len;i++){
		if(s[i]=='|') {                      // ����� '|' ��Ҫͨ�� s1�ж��ܷ���� 
			if(s1[cot]!=s1[cot+1]) cout<<"|";
			else cout<<".";
			cot++;
		}else if(cot<n) cout<<".";           // ������ǵ�ǰλ�õ�������'.'���� 
		 else cout<<s[i];                    // �����ǰ�� 
	}
	if(head->rchild!=NULL||head->lchild!=NULL) cout<<"-|";         // ����������� ���'-|' 
	cout<<endl;
	if(head->lchild!=NULL) 
		s1+="0",dfs(head->lchild,s,n+1,s1),s1 = s1.substr(0,s1.length()-1);
}
int main(){
	int val;
	node *root=NULL;
	while(scanf("%d",&val)!=EOF)
		root=insert(root,val);
	string s = "";
    string s1= ""; 
    fir = root->val;
    dfs(root,s,0,s1);
	return 0;
}
