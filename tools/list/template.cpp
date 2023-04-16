#include<bits/stdc++.h>		//用不来 
using namespace std;
list<int> L;		//list is a linked list链表 
int main(){
	L.insert(L.begin(),0);
	for(int i=1;i<=100;i++){
		L.push_front(-i);
		L.push_back(i);
	}
	for(list<int>::iterator it=L.begin();it!=L.end();it++){
		cout<<*it<<' ';
		L.erase(it);
	}
	return 0;
}
