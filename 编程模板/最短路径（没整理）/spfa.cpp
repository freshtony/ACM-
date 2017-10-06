#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
#include <string.h>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=110000;
bool vis[MAXN];
int head[MAXN];
int dis[MAXN];
int cnt[MAXN];
int ans,m,n;
struct Node
{
    int u,v,next;
    int w;
} edges[MAXN];


/***********************************************************************************
                                    AddEdge（建边）
************************************************************************************/


void AddEdge(int u,int v,int w)
{
    edges[ans].u=u;
    edges[ans].v=v;
    edges[ans].w=w;
    edges[ans].next=head[u];
    head[u]=ans++;
}


/***********************************************************************************
                                     初始化图
************************************************************************************/



void init()
{
    int a,b,c;
    mem(head,-1);
    ans=0;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        AddEdge(a,b,c);
        AddEdge(b,a,c);
    }
}


/***********************************************************************************
                            Spfa求单源最短路&&判断负环
************************************************************************************/


bool Spfa(int st)
{
    queue<int> q;
    mem(vis,0);
    for(int i=1; i<=n; i++) dis[i]=INF;
    vis[st]=true;
    dis[st]=0;
    while(!q.empty()) q.pop();
    mem(cnt,0);
    cnt[st]++;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;;
        for(int i=head[u]; i!=-1; i=edges[i].next)
        {
            int top=edges[i].v;
            if(dis[top]>dis[u]+edges[i].w)
            {
                dis[top]=dis[u]+edges[i].w;
                if(!vis[top])
                {
                    vis[top]=true;
                    q.push(top);
                    if(++cnt[top]>n)
                        return false;//cnt数组大于n证明负环。
                }
            }
        }
    }
    return 0;
}

/***********************************************************************************
                                 主程序
************************************************************************************/
void solve()
{
    scanf("%d%d",&n,&m);
    init();
    Spfa(1);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}

