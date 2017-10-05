#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long LL;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
#define root 1,n,1
const int N=1e4+2;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
double X[4*N],Y[4*N],add[4*N];
void rotate(double &x,double &y,double rad) { //向量（x,y)顺时针旋转rad
	double tx=x*cos(rad)+y*sin(rad);
	double ty=y*cos(rad)-x*sin(rad);
	x=tx;
	y=ty;
}
/***********************************************************************************
                                        向上更新
************************************************************************************/
void PushUp(int rt) {
	X[rt]=X[rt<<1]+X[rt<<1 |1];
	Y[rt]=Y[rt<<1]+Y[rt<<1 |1];
}

/***********************************************************************************
                            向下传递（懒惰算法）(区间修改时加上去）
************************************************************************************/
void PushDown(int rt,int l,int r) {
	if (add[rt]) {			//区间增减
		rotate(X[rt<<1],Y[rt<<1],add[rt]);
		rotate(X[rt<<1 |1],Y[rt<<1 |1],add[rt]);
		add[rt<<1]+=add[rt];
		add[rt<<1 | 1]+=add[rt];
		add[rt]=0;
	}
}



/***********************************************************************************
                                    build(一边读入一边构建)
************************************************************************************/
void build(int l,int r,int rt) {    //
	add[rt]=0;
	if (l==r) {
		scanf("%lf",&Y[rt]);
		X[rt]=0;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);      //构建左子树
	build(rson);      //构建右子树
	PushUp(rt);       //构建完左右两颗子树后，更新当前子树
}



/***********************************************************************************
                                区间增减（l,r)  + add
************************************************************************************/

void interval_add(int L,int R,double addv,int l,int r,int rt) {
	if (L<=l && r<=R) {
		rotate(X[rt],Y[rt],addv);
		add[rt]+=addv;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_add(L,R,addv,lson);
	if(R>m) interval_add(L,R,addv,rson);
	PushUp(rt);
}




/*************************************************************************************************************************
                                                            主程序
**************************************************************************************************************************/
double pre[N];
void solve(int n,int m) {
	build(root);
	for (int i=1; i<=n; i++) pre[i]=pi;
	while(m--) {
		int x;
		double rad;
		scanf("%d%lf",&x,&rad);
		rad=rad/360*2*pi;
		interval_add(x+1,n,pre[x]-rad,root);
		pre[x]=rad;
		printf("%.2f %.2f\n",X[1],Y[1]);
	}
	printf("\n");
}
int main() {
//	freopen("datain.txt","r",stdin);
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		solve(n,m);
	}
	return 0;
}

