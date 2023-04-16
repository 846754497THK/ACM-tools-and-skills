//data generator
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input1.txt","w",stdout);
	srand(int(time(0))); 
	int n=rand()%2000;
	int m=rand()%1000;
	cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<rand()%999999<<" ";
    }
    cout<<endl<<m<<endl;
    for(int i=0;i<m;i++){
        cout<<rand()%999999<<" ";
    }
}
