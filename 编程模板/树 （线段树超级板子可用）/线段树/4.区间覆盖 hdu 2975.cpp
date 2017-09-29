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
const int N=1e5+2;
const int inf=0x3f3f3f3f;
int SUM[4*N],MAX[4*N],MIN[4*N],add[4*N],change[4*N];
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
int ans=-1;
int query_MAX(int wid,int l,int r,int rt) {
	if (l==r) {
		if (MAX[rt]>=wid) {
			MAX[rt]-=wid;
			ans=l;
			PushUp(rt);
		}
		return wid;
	}
	int m=(l+r)>>1;
	int res=query_MAX(wid,lson);
	if (res>=wid) {
		PushUp(rt);
		return res;
	} else {
		res=max( res , query_MAX(wid,rson) );
		if (res>=wid) PushUp(rt);
		return res;
	}
}



/*************************************************************************************************************************
                                                            ������
**************************************************************************************************************************/
void solve(int n) {
	build(1,h,1);
	int wid;
	while(cin>>wid) {
		cout<<"Wid"<<wid<<endl;
		ans=-1;
		query_MAX(wid,1,n,1);
		if (ans==-1) {
			cout<<-1<<endl;
			return;
		} else cout<<ans<<endl;
	}
}

int main() {
	freopen("datain.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>h>>w>>n) {
		cout<<h<<w<<n<<endl;
		solve(n);
	}
	return 0;
}

