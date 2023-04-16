/*
�����EK�㷨��O(V*E*E)
�㷨˼�룺���ҵ�һ������������·P���ٰ�P�еıߵ���С�����������������У����²�������
*/
#include<stdio.h>
#include<string.h>				//���ص������ 
#include<queue>
using namespace std;
#define captype __int64
const int N = 205;
captype cap[N][N],f[N][N],rest[N];
int sNode,eNode,pre[N];
void init(){
    memset(f,0,sizeof(f));
    memset(cap,0,sizeof(cap));
}
bool searchPath(int n){													//��һ������·
    bool vist[N]={0};
    queue<int>q;
    int u,v;
    u=sNode; vist[u]=1;
    pre[u]=u; rest[u]=1<<30;
    q.push(u);
    while(!q.empty()){
        u=q.front(); q.pop();
        for(v=1; v<=n; v++)
        if(!vist[v]&&cap[u][v]-f[u][v]>0)
        {
            vist[v]=1; pre[v]=u;
            if(cap[u][v]-f[u][v]>rest[u])
              rest[v]=rest[u];
            else
                rest[v]=cap[u][v]-f[u][v];
            if(v==eNode) return true;
            q.push(v);
        }
    }
    return false;
}
captype maxflow(int s,int t,int n){
    captype ans=0;
    sNode=s; eNode=t;
    while(searchPath(n)){
        ans+=rest[eNode];
        int v=eNode;
        while(v!=sNode){
            int u=pre[v];
            f[u][v]+=rest[eNode];
            f[v][u]-=rest[eNode];								//��һ�������Ļ���
            v=u;
        }
    }
    return ans;
}
int main(){
    int a,b,c,n,m;
    while(~scanf("%d%d",&n,&m)){							//n�ڵ��� m���� 
        scanf("%d%d",&sNode,&eNode);						//sNodeԴ����������һ����0��ʼ���������·�����Ϊ׼��eNode��� 
        init();
        while(m--){
            scanf("%d%d%d",&a,&b,&c);						//a������b������Ϊc 
            cap[a][b]+=c;
        }
        printf("%d\n",maxflow(sNode,eNode,n));
    }
}
