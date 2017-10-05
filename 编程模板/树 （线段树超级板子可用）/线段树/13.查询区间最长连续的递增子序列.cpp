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
int Rig[4*N],Lef[4*N],Prefix[4*N],Suffix[4*N],Middle[4*N],MAX[4*N],add[4*N];
/***********************************************************************************
                                        向上更新
************************************************************************************/
void PushUp(int rt,int l,int r) {
	Rig[rt]=Rig[rt<<1 | 1];
	Lef[rt]=Lef[rt<<1];
	Middle[rt]=Suffix[rt<<1]+Prefix[rt<<1|1];
	int m=(l+r)>>1;
	if (Rig[rt<<1]<Lef[rt<<1|1]) {
		if (Prefix[rt<<1]==(m-l+1)) Prefix[rt]=Prefix[rt<<1]+Prefix[rt<<1|1];
		if (Suffix[rt<<1|1]==(r-m)) Suffix[rt]=Suffix[rt<<1]+Suffix[rt<<1|1];
	} else {
		Prefix[rt]=Prefix[rt<<1];
		Suffix[rt]=Suffix[rt<<1|1];
	}
	MAX[rt]=max(Middle[ rt],max(Prefix[rt],Suffix[rt]));
}

/***********************************************************************************
                            向下传递（懒惰算法）(区间修改时加上去）
************************************************************************************/
void PushDown(int rt,int l,int r) {
	if (add[rt]) {			//区间增减
		add[rt<<1]+=add[rt];
		add[rt<<1 | 1]+=add[rt];
		int m=(l+r)>>1;
		Rig[rt<<1]+=add[rt];
		Rig[rt<<1|1]+=add[rt];
		Lef[rt<<1]+=add[rt];
		Lef[rt<<1|1]+=add[rt];
		add[rt]=0;
	}
}





/***********************************************************************************
                                    build(一边读入一边构建)
************************************************************************************/
void build(int l,int r,int rt) {    //
	add[rt]=0;
	if (l==r) {
		cin>>Rig[rt];
		Lef[rt]=Rig[rt];
		MAX[rt]=Prefix[rt]=Suffix[rt]=Middle[rt]=1;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);      //构建左子树
	build(rson);      //构建右子树
	PushUp(rt,l,r);       //构建完左右两颗子树后，更新当前子树
}




/***********************************************************************************
                                区间增减（l,r)  + add
************************************************************************************/

void interval_add(int L,int R,int addv,int l,int r,int rt) {
	if (L<=l && r<=R) {
		add[rt]+=addv;
		Rig[rt]+=addv;
		Lef[rt]+=addv;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_add(L,R,addv,lson);
	if(R>m) interval_add(L,R,addv,rson);
	PushUp(rt,l,r);
}




/***********************************************************************************
                                    区间（L,R)求和
************************************************************************************/

int query_SUM(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return MAX[rt];
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	int res=0,t1=0,t2=0;
	if (L<=m) {
		int t=query_SUM(L,R,lson);
		res=max(res,t);
		t1=min(m-L+1,Suffix[rt<<1]);
	}

	if (R>m) {
		int t=query_SUM(L,R,rson);
		res=max(res,t);
		t2=min(R-m,Prefix[rt<<1|1]);
	}
	if (Rig[rt<<1]<Lef[rt<<1|1])
		res=max(res,t1+t2);
	return res;
}




/*************************************************************************************************************************
                                                            主程序
**************************************************************************************************************************/
void solve() {
	int n,Q;
	cin>>n>>Q;
	build(root);
	while(Q--) {
		char order;
		cin>>order;
		if (order=='q') {
			int a,b;
			cin>>a>>b;
			cout<<query_SUM(a,b,root)<<endl;
		} else {
			int a,b,c;
			cin>>a>>b>>c;
			interval_add(a,b,c,root);
		}
	}
}

int main() {
//	freopen("datain.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		cout<<"Case #"<<i<<":"<<'\n';
		solve();
	}
	return 0;
}

