#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath> 
using namespace std; 
const int N=1e5+5;			//��Ʒ������ 
const int MAXV=1e5+5;		//����������� 
typedef long long LL;


/*********************************************************************************************
										 ��ȫ����
							V�����ı��� 
							N����Ʒ��ÿ����Ʒ����v[i],��ֵw[i]
							ÿ����Ʒ��ȡ���޴� 
							�ʱ�����װ���µ�����»�õ����ļ�ֵ 
*********************************************************************************************/ 
LL dp[MAXV],w[N],v[N];
LL KnapSack(int n,int V) {
	for(int i=0; i<n; i++)
		for(int j=w[i]; j<=V; j++)
			 dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	return dp[V];
}





/*********************************************************************************************
										������
*********************************************************************************************/ 
void solve(){
	int n,V;
	cout<<"�����뱳���������������Ʒ��:"<<endl;
	cin>>V>>n;
	cout<<"������������Ʒ���������ֵ"<<endl;
	for(int i=0;i<n; i++) cin>>v[i]>>w[i];
	cout<<"�����Ʒ��ֵΪ:"<<KnapSack(n,V)<<endl;
}
int main() {
	//�ļ����� �� ȡ��ͬ�����ٶ��� 
	//freopen("datain.txt","r",stdin);	�ļ����
	ios::sync_with_stdio;
	cin.tie(0); 
	
	//����  
	int T;		//T������ 
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}
