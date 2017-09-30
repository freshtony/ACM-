#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
#define root 1,n,1
const int N=222222;
const int inf=0x3f3f3f3f;
int MAX[4*N];
int h,w;
/***********************************************************************************
                                        ���ϸ���
************************************************************************************/
void PushUp(int rt) {
	MAX[rt]=max( MAX[rt<<1] , MAX[rt<<1 | 1]);
}

/***********************************************************************************
                                    build(һ�߶���һ�߹���)
************************************************************************************/
void build(int l,int r,int rt) {    //
	if (l==r) {
		MAX[rt]=w;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);      //����������
	build(rson);      //����������
	PushUp(rt);       //�������������������󣬸��µ�ǰ����
}



/***********************************************************************************
                                    ���䣨L,R)�����ֵ
************************************************************************************/

int query_MAX(int wid,int l,int r,int rt) {
	if (MAX[rt]<wid) return -1;
	if (l==r) {
		if (MAX[rt]>=wid) {
			MAX[rt]-=wid;
			return l;
		}
		else return -1;
	}

	int m=(l+r)>>1;
	if (MAX[rt<<1]<wid){
		int res=query_MAX(wid,rson);
		PushUp(rt);
		return res;
	}else{
		int res=query_MAX(wid,lson);
		PushUp(rt);
		return res;
	}
}



/*************************************************************************************************************************
                                                            ������
**************************************************************************************************************************/
void solve(int n) {
	int t=min(n,h);
	build(1,t,1);
	for (int i=0;i<n;i++) {
		int wid;
		cin>>wid;
		int ans;
		ans=query_MAX(wid,1,t,1);
		if (ans==-1) {
			cout<<-1<<'\n';
		} else cout<<ans<<'\n';
	}
}

int main() {
//	freopen("datain.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>h>>w>>n) {
		solve(n);
	}
	return 0;
}

