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
const LL N=1e5+2;
const LL inf=0x3f3f3f3f;
LL SUM[4*N],add[4*N];
/***********************************************************************************
                                        ���ϸ���
************************************************************************************/
void PushUp(LL rt) {
	SUM[rt]=SUM[rt<<1]+SUM[rt<<1 | 1];
}

/***********************************************************************************
                            ���´��ݣ������㷨��(�����޸�ʱ����ȥ��
************************************************************************************/
void PushDown(LL rt,LL l,LL r) {
	if (add[rt]) {			//��������
		add[rt<<1]+=add[rt];
		add[rt<<1 | 1]+=add[rt];
		LL m=(l+r)>>1;
		SUM[rt<<1]+=add[rt]*(m-l+1);
		SUM[rt<<1 | 1]+=add[rt]*(r-m);
		add[rt]=0;
	}
}


/***********************************************************************************
                                    build(һ�߶���һ�߹���)
************************************************************************************/
void build(LL l,LL r,LL rt) {    //
	add[rt]=0;
	if (l==r) {
		cin>>SUM[rt];
		return ;
	}
	LL m=(l+r)>>1;
	build(lson);      //����������
	build(rson);      //����������
	PushUp(rt);       //�������������������󣬸��µ�ǰ����
}





/***********************************************************************************
                                ����������l,r)  + add
************************************************************************************/

void interval_add(LL L,LL R,LL addv,LL l,LL r,LL rt) {
	if (L<=l && r<=R) {
		add[rt]+=addv;
		SUM[rt]+=addv*(r-l+1);
		return ;
	}
	PushDown(rt,l,r);
	LL m=(l+r)>>1;
	if(L<=m) interval_add(L,R,addv,lson);
	if(R>m) interval_add(L,R,addv,rson);
	PushUp(rt);
}


/***********************************************************************************
                                    ���䣨L,R)���
************************************************************************************/

LL query_SUM(LL L,LL R,LL l,LL r,LL rt) {
	if (L<=l && r<=R) {
		return SUM[rt];
	}
	PushDown(rt,l,r);
	LL m=(l+r)>>1;
	LL res=0;
	if (L<=m) res+=query_SUM(L,R,lson);
	if (R>m)  res+=query_SUM(L,R,rson);
	return res;
}



/*************************************************************************************************************************
                                                            ������
**************************************************************************************************************************/
void solve(LL n,LL q) {
	build(root);
	while(q--){
		char order;
		cin>>order;
		if (order=='Q'){
			LL a,b;
			cin>>a>>b;
			cout<<query_SUM(a,b,root)<<endl;
		}else{
			LL a,b,c;
			cin>>a>>b>>c;
			interval_add(a,b,c,root);
		}
	}
}

int main() {
//	freopen("datain.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	LL n,q; 
	while(cin>>n>>q) {
		solve(n,q);
	}
	return 0;
}

