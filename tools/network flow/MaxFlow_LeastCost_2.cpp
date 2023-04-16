#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#define maxn 5002
#define inf 1e9
using namespace std;
int n,m,S,T,head[maxn],tot=1,t1,t2,t3,t4,fl;
int d[maxn],flag[maxn],ans,cur[maxn];
struct node{
    int v,nex,cap,w;
}e[100002];
void lj(int t1,int t2,int t3,int t4){
    tot++;e[tot].v=t2;e[tot].cap=t3;e[tot].w=t4;e[tot].nex=head[t1];head[t1]=tot;
}
bool spfa(){
    for(int i=1;i<=n;i++)d[i]=inf,flag[i]=0;
    queue<int>q;q.push(S);d[S]=0;
    while(!q.empty()){
        
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].nex){
            if(e[i].cap>0&&d[e[i].v]>d[x]+e[i].w){
                d[e[i].v]=d[x]+e[i].w;
                if(!flag[e[i].v])flag[e[i].v]=1,q.push(e[i].v);
            }
        }
        flag[x]=0;
    }
    return d[T]!=inf;
}
int dfs(int k,int a){
    flag[k]=1;
    if(k==T||a==0)return a;
    int f,flow=0;
    for(int &i=cur[k];i;i=e[i].nex){
        if(d[e[i].v]==d[k]+e[i].w&&e[i].cap&&!flag[e[i].v]){//attention!!!
            f=dfs(e[i].v,min(e[i].cap,a));
            flow+=f;a-=f;e[i].cap-=f;e[i^1].cap+=f;
            ans+=f*e[i].w;
            if(a==0)break;
        }
    }
    return flow;
}
int main(){
    cin>>n>>m>>S>>T;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
        lj(t1,t2,t3,t4);lj(t2,t1,0,-t4);
    }
    while(spfa()){
        flag[T]=1;
        while(flag[T]){
            memset(flag,0,sizeof(flag));
            for(int i=1;i<=n;i++)cur[i]=head[i];
            fl+=dfs(S,inf);
        }
    }
    cout<<fl<<' '<<ans<<endl;
    return 0;
}
