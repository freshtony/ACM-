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
int SUM[4*N],MAX[4*N],MIN[4*N],add[4*N],assign[4*N];
/***********************************************************************************
                                        向上更新
************************************************************************************/
void PushUp(int rt) {
	SUM[rt]=SUM[rt<<1]+SUM[rt<<1 | 1];
	MAX[rt]=max( MAX[rt<<1] , MAX[rt<<1 | 1]);
	MIN[rt]=min( MIN[rt<<1] , MIN[rt<<1 | 1]);
}

/***********************************************************************************
                            向下传递（懒惰算法）(区间修改时加上去）
************************************************************************************/
void PushDown(int rt,int l,int r) {
	if (add[rt]) {			//区间增减
		add[rt<<1]+=add[rt];
		add[rt<<1 | 1]+=add[rt];
		int m=(l+r)>>1; 
		SUM[rt<<1]+=add[rt]*(m-l+1);
		SUM[rt<<1 | 1]+=add[rt]*(r-m);
		MAX[rt<<1]+=add[rt];
		MAX[rt<<1 | 1]+=add[rt];
		MIN[rt<<1]+=add[rt];
		MIN[rt<<1 | 1]+=add[rt];
		add[rt]=0;
	}
	if(assign[rt]) {			//区间赋值
		assign[rt<<1]=assign[rt];
		assign[rt<<1 | 1]=assign[rt];
		int m=(l+r)>>1;
		SUM[rt<<1]=(m-l+1)*assign[rt];
		SUM[rt<<1 | 1]=(r-m)*assign[rt];
		MAX[rt<<1]+=add[rt];
		MAX[rt<<1 | 1]+=add[rt];
		MIN[rt<<1]+=add[rt];
		MIN[rt<<1 | 1]+=add[rt];
		assign[rt]=0;
	}
}





/***********************************************************************************
                                    build(一边读入一边构建)
************************************************************************************/
void build(int l,int r,int rt) {    //
	add[rt]=0;
	assign[rt]=0;
	if (l==r) {
		cin>>SUM[rt];
		MAX[rt]=SUM[rt];
		MIN[rt]=SUM[rt];
		return ;
	}
	int m=(l+r)>>1;
	build(lson);      //构建左子树
	build(rson);      //构建右子树
	PushUp(rt);       //构建完左右两颗子树后，更新当前子树
}





/***********************************************************************************
                                    单点增减 p位置+add
************************************************************************************/

void point_add(int p,int addv,int l,int r,int rt) {
	if (l==r) {
		SUM[rt]+=addv;
		MAX[rt]+=addv;
		MIN[rt]+=addv;
		return ;
	}
	int m=(l+r)>>1;
	if (p<=m) point_add(p,addv,lson);
	else      point_add(p,addv,rson);
	PushUp(rt);
}


/***********************************************************************************
                                单点赋值（单点修改） p位置=add
************************************************************************************/

void point_assign(int p,int val,int l,int r,int rt) {
	if (l==r) {
		SUM[rt]=val;
		MAX[rt]=val;
		MIN[rt]=val;
		return ;
	}
	int m=(l+r)>>1;
	if (p<=m) point_assign(p,val,lson);
	else      point_assign(p,val,rson);
	PushUp(rt);
}

/***********************************************************************************
                                区间增减（l,r)  + add
************************************************************************************/

void interval_add(int L,int R,int addv,int l,int r,int rt) {
	if (L<=l && r<=R) {
		add[rt]+=addv;
		SUM[rt]+=addv*(r-l+1);
		MAX[rt]+=addv;
		MIN[rt]+=addv;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_add(L,R,addv,lson);
	if(R>m) interval_add(L,R,addv,rson);
	PushUp(rt);
}

/***********************************************************************************
                                区间赋值（l,r)  = val
************************************************************************************/

void interval_assign(int L,int R,int val,int l,int r,int rt) {
	if (L<=l && r<=R) {
		assign[rt]=val;
		SUM[rt]=val*(r-l+1);
		MAX[rt]=val;
		MIN[rt]=val;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_assign(L,R,val,lson);
	if(R>m) interval_assign(L,R,val,rson);
	PushUp(rt);
}


/***********************************************************************************
                                    区间（L,R)求和
************************************************************************************/

int query_SUM(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return SUM[rt];
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	int res=0;
	if (L<=m) res+=query_SUM(L,R,lson);
	if (R>m)  res+=query_SUM(L,R,rson);
	return res;
}

/***********************************************************************************
                                    区间（L,R)求最大值
************************************************************************************/

int query_MAX(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return MAX[rt];
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	int res=-inf;
	if (L<=m) res=max( res , query_MAX(L,R,lson) );
	if (R>m)  res=max( res , query_MAX(L,R,rson) );
	return res;
}

/***********************************************************************************
                                    区间（L,R)求最小值
************************************************************************************/

int query_MIN(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return MAX[rt];
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	int res=inf;
	if (L<=m) res=min( res , query_MIN(L,R,lson) );
	if (R>m)  res=min( res , query_MIN(L,R,rson) );
	return res;
}



/*************************************************************************************************************************
                                                            主程序
**************************************************************************************************************************/
void solve() {
	int n;
	cin>>n;
	build(root);
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}

