#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
const int N=65536*2+1;
const int inf=0x3f3f3f3f;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
#define root 0,N,1
int assign[4*N+20],XOR[4*N+20],ans[2*N+10];
/***********************************************************************************
                            		异或 
************************************************************************************/
void reserve(int rt){
	if (assign[rt]!=-1) assign[rt]^=1;
	else XOR[rt]^=1;
} 

/***********************************************************************************
                            向下传递（懒惰算法）(区间修改时加上去）
************************************************************************************/
void PushDown(int rt,int l,int r) {
	if (assign[rt]!=-1) {
		assign[rt<<1]=assign[rt<<1 | 1]=assign[rt];
		assign[rt]=-1;
		XOR[rt<<1]=XOR[rt<<1 | 1]=0;
	}
	if (XOR[rt]) {
		reserve(rt<<1);
		reserve(rt<<1 | 1);
		XOR[rt]=0;
	}
}


/***********************************************************************************
                                区间赋值（l,r)  = val
************************************************************************************/

void interval_assign(int L,int R,int val,int l,int r,int rt) {
	if (L<=l && r<=R) {
		assign[rt]=val;
		XOR[rt]=0;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_assign(L,R,val,lson);
	if(R>m) interval_assign(L,R,val,rson);
}

/***********************************************************************************
                                	区间异或 
************************************************************************************/

void FXOR(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		reserve(rt);
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) FXOR(L,R,lson);
	if(R>m) FXOR(L,R,rson);
}


/***********************************************************************************
                                    区间（L,R)
************************************************************************************/
void query(int l,int r,int rt) {
	if (l==r) {
		ans[l]=assign[rt];
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
	memset(assign,0,sizeof(assign));
	memset(XOR,0,sizeof(XOR));
	memset(ans,0,sizeof(ans)); 
	char ch0,ch1,ch2;
	int L,R;
	while(scanf(" %c %c%d,%d%c",&ch0,&ch1,&L,&R,&ch2)!=EOF) {
		L<<=1;
		R<<=1;
		if (ch1=='(') L++;
		if (ch2==')') R--;
		if (L>R) {
			if (ch0=='I' || ch0=='C') {
				assign[1]=XOR[1]=0;
			}
			continue;
		}
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
				if(L>0) interval_assign(0,L-1,0,root);
				if (R<N) interval_assign(R+1,N,0,root);
				break;
			}
			case 'S': {
				FXOR(L,R,root);
				break;
			}
			case 'C': {
				if(L>0) interval_assign(0,L-1,0,root);
				if (R<N) interval_assign(R+1,N,0,root);
				FXOR(L,R,root);
				break;
			}
		}
	}
	query(0,N,1);
	L=0;R=-1;
	for (int i=0; i<=N; i++) {
		if (ans[i]==0 && ans[i+1]==1) L=i+1;
		if (ans[i]==1 && ans[i+1]==0) {
			R=i;
			if (L&1) printf("(%d,",L/2);
			else		  printf("[%d,",L/2);
			if (R&1) 	  printf("%d) ",R/2+1);
			else		  printf("%d] ",R/2);
		}
	}
	if (L>R)	printf("empty set\n");
	else printf("\n");
}

int main() {
//	freopen("datain.txt","r",stdin);
	solve();
	return 0;
}

