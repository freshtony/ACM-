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
/***********************************************************************************
                                        ���ϸ���
************************************************************************************/
void PushUp(int rt) {
	SUM[rt]=SUM[rt<<1]+SUM[rt<<1 | 1];
}


/***********************************************************************************
                                    build(һ�߶���һ�߹���)
************************************************************************************/
void build(int l,int r,int rt) {    //
	if (l==r) {
		SUM[rt]=0;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);      //����������
	build(rson);      //����������
	PushUp(rt);       //�������������������󣬸��µ�ǰ����
}



/***********************************************************************************
                                ���㸳ֵ�������޸ģ� pλ��=add
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
                                    ���䣨L,R)���
************************************************************************************/

int query_SUM(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return SUM[rt];
	}
	int m=(l+r)>>1;
	int res=0;
	if (L<=m) res+=query_SUM(L,R,lson);
	if (R>m)  res+=query_SUM(L,R,rson);
	return res;
}



/*************************************************************************************************************************
                                                            ������
**************************************************************************************************************************/
void solve() {
	int n;
	cin>>n;
	build(root);
}

int main() {
//	freopen("datain.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>n){
		int x[n];
		build(1,n,1);
		int sum=0;
		for (int i=0;i<n;i++){
			cin>>x[i];
			x[i]++;
			sum+=query_SUM(x[i],n,1,n,1);
			point_assign(x[i],1,1,n,1);
		}		
		int ans=sum;
		for (int i=0;i<n;i++){
			sum+=(n-x[i]-x[i]+1);
			ans=min(ans,sum);
		}
		cout<<ans<<endl; 
	}
	return 0;
}

