#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int N=1e6+5;
const int mod=1e9+7;

/*********************************************************************************************
							ŷ������O(n) +������� + Ī����˹���� 
							
*********************************************************************************************/ 
void build_phi(){
	memset(phi,0,sizeof(phi));
	phi[i]=1;
	for (int i=2;i<=N;i++) {
		if (!phi[i]) {
			primes.push_back(i);
			phi[i]=i-1;
			mu[i]=-1; 
		}
		for (int j=0;j<primes.size() && i*primes[j]<N;j++){
			if (i%primes[j]){
				phi[i*primes[j]]=phi[i]*(primes[j]-1);
				mu[i*primes[j]]=-mu[i];
			}else{
				phi[i*primes[j]]=phi[i]*primes[j];
				mu[i*primes[j]]=0;
				break;
			}
		}
	}
}










/*********************************************************************************************
										������
*********************************************************************************************/ 

void solve() {
	LL a,p;
	cin>>a>>p;
	cout<<get_inv(a,p)<<endl;
}

int main() {
//�ļ����� 
//	freopen("datain.txt","r",stdin);

//ȡ�����壬���ٶ��� 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//���� 
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
