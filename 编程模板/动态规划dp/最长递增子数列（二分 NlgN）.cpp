 #include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int Longest_NonDecreasing_Subsequence(int a[],int n){
	int b[n+1];
	memset(b,0,sizeof(b));
	int maxlen=0; 
	for (int i=1; i<=n; i++) {												//���� 
		if (a[i]>b[maxlen])	b[++maxlen]=a[i];						
		else {
			int pos=lower_bound(b+1,b+maxlen+1,a[i])-b;
			b[pos]=a[i];
		}
	}
	return maxlen;
}


/*********************************************************************************************
										������
*********************************************************************************************/ 
void solve(){
	int n;
	cin>>n; 
	int a[n+1];
	for (int i=1;i<=n;i++) cin>>a[i];
	cout<<"The max len= "<<Longest_NonDecreasing_Subsequence(a,n);
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
