#include<bits/stdc++.h>
using namespace std;
struct mm{
	int num;
	string s;
};
int main(){
	mm a[100],b;
	vector<mm> vec;
	for(int i=0;i<95;i++){
		a[i].num=i;
		a[i].s="2333";
		vec.push_back(a[i]);
	}
	cout<<vec.size()<<endl;
	vec.pop_back();
	cout<<vec.size()<<endl;
	cout<<endl;
	
	cout<<vec[40].num<<endl;
	b.num=996;	b.s="$_$";
	vec.insert(vec.begin()+40,b);			//这里插入的点是真实的地址，要用到vec. begin() & vec.end()
	cout<<vec[40].num<<endl;
	cout<<endl;
	
	vec.erase(vec.begin());
	cout<<vec[39].num<<endl;
	cout<<endl;
	
	cout<<vec[93].num<<endl;
	vec.erase(vec.end());
	vec.erase(vec.end());
	cout<<vec.size()<<endl;
	cout<<vec[93].num<<endl;			//还是可以输出？？ 
	cout<<endl;
	
	vec.clear();
	cout<<vec[93].num<<endl;
	cout<<endl;
	
	return 0;
} 
