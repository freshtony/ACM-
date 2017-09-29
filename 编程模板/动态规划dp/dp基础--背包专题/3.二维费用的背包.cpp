#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1e5+5;
const int MAXV=1e3+5;		//����������� 
const int MAXM=1e3+5;		//�����÷��� 
typedef long long LL;


/*********************************************************************************************
										��ά���õı��� 
								V����������MԪ���� 
								ÿ����Ʒv[i]������m[i]���ã�w[i]��ֵ 
								����V,M�¿ɻ�õ�����ֵ 
*********************************************************************************************/
LL dp[MAXV][MAXM],v[N],m[N],w[N];
LL KnapSack(int n,int V,int M) {
	for(int i=0; i<n; i++)
		for(int j=w[i]; j<V; j++)
			for(int k=m[i]; k<=M; k++)
				dp[j][k]=max(dp[j][k],dp[j-v[i]][k-m[i]]+w[i]);
	return dp[V][M];
}





/*********************************************************************************************
										������
*********************************************************************************************/
void solve() {
	int n,V,M;
	cout<<"�����뱳������Ʒ��������������ܿ��÷���:"<<endl;
	cin>>n>>V>>M;
	cout<<"������������Ʒ�����뻨�����ֵ"<<endl;
	for(int i=0; i<n; i++) cin>>v[i]>>m[i]>>w[i];
	cout<<"�����Ʒ��ֵΪ:"<<KnapSack(n,V,M)<<endl;
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
