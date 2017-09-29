/* ------------------------------------
		by 16��ACM�᳤ ֣���
		ģ���д�˽���� QQ��531584268
		���������������˽��
----------------------------------- */
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stdlib.h>
using namespace std;
typedef long long LL;
const int N=1e6+7;
const int mod=1e9+7;
LL A[N],Atmp[N];

/*********************************************************************************************
										�鲢����
									  1��������� 
									  2�������ұ�
									  3���ϲ� 
*********************************************************************************************/

void merge_sort(int L,int R) {
	//TODO 1���жϱ߽� 
	if (L>=R) return;	
	int mid=L + (R-L)/2;
	
	//TODO 2���������
	merge_sort(L,mid);
	
	//TODO 3�������ұ�
	merge_sort(mid+1,R);
	
	//TODO 4: �������ߺϲ�,����������ʱ����Atmp�� 
	int i=L,j=mid+1;
	int t=L;
	while(i<=mid || j<=R) {
		if ( j>R || (i<=mid && A[i]<=A[j]))
			Atmp[t++]=A[i++];
		else
			Atmp[t++]=A[j++];
	} 
	//TODO 5���Ѹ�������Atmp���ƻ�A����
	for (int i=L; i<=R; i++) A[i]=Atmp[i]; 
	return;
}









/*********************************************************************************************
										������
*********************************************************************************************/

void solve() {
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>A[i];
	merge_sort(1,n);
	for (int i=1;i<=n;i++) cout<<A[i]<<" ";
	cout<<endl; 
}

int main() {
//�ļ�����
	freopen("datain.txt","r",stdin);

//ȡ�����壬���ٶ���
	ios::sync_with_stdio(false);
	cin.tie(0);

//����
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}
