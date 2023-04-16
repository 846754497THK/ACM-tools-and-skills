#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
int main(int argc, const char * argv[]) {
    int b, i, la, lc, x;
    string str;
    int a[MAX], c[MAX];
    while(cin >> str >> b) {
        memset(a, 0, sizeof(a)); 
        memset(c, 0, sizeof(c));
        la = (int)str.size();
        for(i = 0; i < la; i++)
            a[la-i-1] = str[i] - '0';
        x = 0; //x 余数 
        for(i = la-1; i >= 0; i--) {
            c[i] = (x * 10 + a[i]) / b; 
            x = (x * 10 + a[i]) % b;
        }
        lc = la;
        while(lc > 1 && c[lc-1] == 0) 
            lc--;
        for(i = 0; i < lc; i++)
            cout << c[lc-i-1];
        // 空格输出余数
        cout << " " << x << endl;
    }
    return 0;
}
