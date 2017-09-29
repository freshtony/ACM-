#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1e5+5;
const int MAXW=1e3+5;
const int MAXU=1e3+5;
typedef long long LL;


/*********************************************************************************************
										�޶��ܸ����ı��� 
							V�����ı��� 
							N����Ʒ��ÿ����Ʒ����v[i],��ֵw[i]
							ÿ����Ʒ���ȡ1�Σ����ܹ����ȡK����Ʒ 
							�ʱ�����װ���µ�����»�õ����ļ�ֵ 
*********************************************************************************************/
LL dp[MAXW][MAXU],v[N],w[N];
LL KnapSack(int n,int W,int U) {
	for(int i=0; i<n; i++)
		for(int j=w[i]; j<=W; j++)
			for(int k=1; k<=U; k++)
				dp[j][k]=max(dp[j][k],dp[j-w[i]][k-1]+v[i]);
	return dp[W][U];
}





/*********************************************************************************************
										������
*********************************************************************************************/
void solve() {
	int n,W,U;
	cout<<"�����뱳������Ʒ��������������ܸ���:"<<endl;
	cin>>n>>W>>U;
	cout<<"������������Ʒ�������뻨�����ֵ"<<endl;
	for(int i=0; i<n; i++) cin>>w[i]>>v[i];
	cout<<"�����Ʒ��ֵΪ:"<<KnapSack(n,W,U)<<endl;
}
int main() {
	//�ļ����� �� ȡ��ͬ�����ٶ���
	//freopen("datain.txt","r",stdin);	�ļ����
	ios::sync_with_stdio;
	cin.tie(0);

	//����
	int T;		//T������
	cin>>T;
	while(T--) {
		solve();
	}

	return 0;
}
