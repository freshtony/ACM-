#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
#define root 0,n,1
const int N=1e5+2;
const int inf=0x3f3f3f3f;
int change[4*N],XOR[4*N];
/***********************************************************************************
                            向下传递（懒惰算法）(区间修改时加上去）
************************************************************************************/
void PushDown(int rt,int l,int r) {
	if (change[rt]!=-1) {
		change[rt<<1]=change[rt<<1 | 1]=change[rt];
		change[rt]=-1;
		XOR[rt]=XOR[rt<<1]=XOR[rt<<1 | 1]=0;
	}
	if (XOR[rt]) {
		if (change[rt<<1]!=-1) change[rt<<1]^=1;
		else XOR[rt<<1]^=1;
		if (change[rt<<1 | 1]!=-1) change[rt<<1 |1]^=1;
		else XOR[rt<<1 |1]^=1;
		XOR[rt]=0;
	}
}


/***********************************************************************************
                                区间赋值（l,r)  = val
************************************************************************************/

void interval_assign(int L,int R,int val,int l,int r,int rt) {
	if (l>r) return;
	if (L<=l && r<=R) {
		change[rt]=val;
		XOR[rt]=0;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_assign(L,R,val,lson);
	if(R>m) interval_assign(L,R,val,rson);
}

/***********************************************************************************
                                区间赋值（l,r)  = val
************************************************************************************/

void turn_01(int L,int R,int l,int r,int rt) {
	if (l>r) return;
	if (L<=l && r<=R) {
		if (change[rt]!=-1) change[rt]^=1;
		else XOR[rt]^=1;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) turn_01(L,R,lson);
	if(R>m) turn_01(L,R,rson);
}


/***********************************************************************************
                                    区间（L,R)求和
************************************************************************************/

void query(int l,int r,int rt) {
	if (l==r) {
		if (change[rt]==1) cout<<l<<"  ";
		return;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	query(lson);
	query(rson);
	return ;
}



/*************************************************************************************************************************
                                                            主程序
**************************************************************************************************************************/
void solve() {
	memset(change,-1,sizeof(change));
	char ch0,ch1,ch2,ch3;
	int L,R;
	int n=N;
	while(cin>>ch0>>ch1>>L>>ch2>>R>>ch3) {
		if (L>R) continue;
		L<<=1;
		R<<=1;
		
		if (ch1=='(') L++;
		if (ch3==')') R--;
	
		switch(ch0) {
			case 'U': {
				interval_assign(L,R,1,root);
				break;
			}
			case 'D': {
				interval_assign(L,R,0,root);
				break;
			}
			case 'I': {
				interval_assign(0,L-1,0,root);
				interval_assign(R+1,N,0,root);
				break;
			}
			case 'S': {
				turn_01(L,R,root);
				break;
			}
			case 'C': {
				interval_assign(0,L-1,0,root);
				interval_assign(R+1,N,0,root);
				turn_01(L,R,root);
				break;
			}
		}
		cout<<ch0<<"  "<<L<<"  "<<R<<endl;
		query(0,n,1);
		cout<<endl;
	}
	
}

int main() {
	freopen("datain.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

