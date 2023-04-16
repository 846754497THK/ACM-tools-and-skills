//binary tree simulation 
#include<bits/stdc++.h>				//success
using namespace std;
struct node{
	int num;
	node *l,*r,*fa;	
	node(){};
	node(int x):num(x){};
	void exchange(node *x){
		int tmp;
		tmp=x->num;
		x->num=num;
		num=tmp;
	}
	void Checkit(node *root){
		if(this==root)return;
		if(num < fa->num){
			exchange(fa);
			fa->Checkit(root);
		}
		return;
	}
};
struct binary_tree{
	node root;
	binary_tree(){};
	binary_tree(node x):root(x){};
	void Check(node *x){
		x->Checkit(&root);
		return;
	}
	void Push(node){
		
	}
};
int main(){
	int n;
	n=10;
	node a[12],p;
	a[0]=-1;
	binary_tree A(a[0]);
	for(int i=1;i<=10;i++){
		a[i].num=i*i%97*i%97;
		a[i-1].l=&a[i];
		a[i].fa=&a[i-1];
		A.Check(&a[i]);
	}
	for(int i=1;i<=10;i++)printf("%d ",a[i].num);
	printf("\n");
	p=a[10];
	while(p.num!=-1){
		printf("%d\n",p.num);
		p=*p.fa;
	}
	return 0;
}
