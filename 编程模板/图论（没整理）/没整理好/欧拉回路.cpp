#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#include <stack>

bool vis[2000];
int G[50][2000];
stack <int> res;
int in[50];
int N,M;
void init() {
	memset(vis,0,sizeof(vis));
	memset(in,0,sizeof(in));
	memset(G,0,sizeof(G));
}
void euler(int n) {
	for(int i=0; i<=M; i++) {
		if(!G[n][i]||vis[i]) continue;
		vis[i]=1;
		euler(G[n][i]);
		res.push(i);
	}
}

int main() {
	int s,t;
//	freopen("data.txt","r",stdin);
	while(scanf("%d%d",&s,&t)==2 ) {
		if (!s && !t) break;
		while(!res.empty()) res.pop();
		init();
		int sta=min(s,t);
		int id;
		N=max(s,t);
		scanf("%d",&id);
		M=id;
		G[s][id]=t;
		G[t][id]=s;
		in[s]++;
		in[t]++;
		while(scanf("%d%d",&s,&t)==2 ) {
			if (!s && !t) break;
			scanf("%d",&id);
			G[s][id]=t;
			G[t][id]=s;
			in[s]++;
			in[t]++;
			M=max(id,M);
			N=max(s,N);
			N=max(t,N);
		}
		//TODO 1:  �ж��Ƿ�ɻ������������ȾͲ��ɻ�
		bool flag=0;
		for(int i=1; i<=N; i++) {
			if(in[i]&1) {
				printf("Round trip does not exist.\n");
				flag=1;
				break;
			}
		}
		//TODO 2�� �ܳɻ��������staΪ��㣬staΪ�յ��ŷ����·
		if(flag) continue;
		euler(sta);
		//TODO 3�� �������֤���һ��û�пո�,��ֻ�лس�
		printf("%d",res.top());
		res.pop();
		while(!res.empty()) {
			printf(" %d",res.top());
			res.pop();
		}
		printf("\n");
	}
	return 0;
}
