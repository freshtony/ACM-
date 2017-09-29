#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int N=1e6+5;
const int mod=1e9+7;


/********************************************************************************************
										����չ�� 
********************************************************************************************/ 
LL fac[15];
void init(){
	fac[1]=1;
	for (int i=2;i<=11;i++) fac[i]=fac[i-1]*i;
}
void cantor(int s[], LL num, int k){//����չ������һ������numչ����һ������s��k�����鳤��
    int t;
    bool h[k];//0��k-1����ʾ�Ƿ���ֹ� 
    memset(h, 0, sizeof(h)); 
    for(int i = 0; i < k; i ++){
        t = num / fac[k-i-1];
        num = num % fac[k-i-1];
        for(int j = 0, pos = 0; ; j ++, pos ++){
            if(h[pos]) j --;
            if(j == t){
                h[pos] = true;
                s[i] = pos + 1;
                break;
            }
        }
    }
}



/********************************************************************************************
										������չ�� 
********************************************************************************************/ 


void inv_cantor(int s[], LL &num, int k){//������չ������һ������s�����һ������num 
    int cnt;
    num = 0;
    for(int i = 0; i < k; i ++){
        cnt = 0;
        for(int j = i + 1; j < k; j ++){
            if(s[i] > s[j]) cnt ++;//�жϼ�����С����
        }
        num += fac[k-i-1] * cnt;
    }
}










/********************************************************************************************
										������ 
********************************************************************************************/ 

void solve() {
	
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
