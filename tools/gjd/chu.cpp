#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300;
char s1[MAXN]={};
char s2[MAXN]={};
int tmp[MAXN]={};
int a[MAXN]={};
int b[MAXN]={};
int c[MAXN]={};
int compare(int a[], int b[]){
    if (a[0]>b[0]){
        return 1;
    } else if (a[0]<b[0]){
        return -1;
    }
    for (int i=a[0]; i>0; i--){
        if (a[i]>b[i]) {
            return 1;
        } else if (a[i]<b[i]){
            return -1;
        }
    }
    return 0;
}
void numcpy(int a[],int b[],int dest){
    for (int i=1;i<=a[0];i++){
        b[i+dest-1] =a[i];
    }
    b[0] = a[0]+dest-1;
}

int main() {
    scanf("%s %s", s1, s2);
    bool flaga = false;
    if ('-'==s1[0]) {
        flaga = true;
        strcpy(s1, &s1[1]);
    }
    bool flagb = false;
    if ('-'==s2[0]) {
        flagb = true;
        strcpy(s2, &s2[1]);
    }
    if (true==flaga && false==flagb) {
        printf("-");
    }
    int len = strlen(s1);
    a[0] = len;
    for (int i=0; i<len; i++) {
        a[len-i]=s1[i]-'0';
    }
    len = strlen(s2);
    b[0] = len;
    for (int i=0; i<len; i++) {
        b[len-i]=s2[i]-'0';
    }

    if (0==compare(a,b)) {
        printf("1\n0\n");
        return 0;
    } else if (-1==compare(a,b)) {
        printf("0\n");
        if (true==flaga) {
            printf("-");
        }
        printf("%s\n", s1);
        return 0;
    } else {
        c[0] = a[0]-b[0]+1;
        for (int i=c[0]; i>0; i--) {
            memset(tmp, 0, sizeof(tmp));
            numcpy(b,tmp,i);
            while (compare(a, tmp)>=0) {
                c[i]++;
                for (int j=1; j<=a[0]; j++) {
                    if (a[j]<tmp[j]) {
                        a[j+1]--;
                        a[j]+=10;
                    }
                    a[j]-=tmp[j];
                }

                int k=a[0];
                while (a[k]==0) {
                    k--;
                }
                a[0]=k;
            }
        }
        while (c[0]>0 && c[c[0]]==0) {
            c[0]--;
        }
    }
    for (int i=c[0]; i>0; i--) {
        printf("%d", c[i]);
    }
    printf("\n");
    if (0==a[0]) {
        printf("0\n");
    } else {
        if (true==flaga) {
            printf("-");
        }
        for (int i=a[0]; i>0; i--) {
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
