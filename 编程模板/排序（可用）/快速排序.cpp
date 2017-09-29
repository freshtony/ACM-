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
int a[N];

/*********************************************************************************************
										��������
										����L��R	
									  1.ȡLλ��Ϊ��׼�����Ȼ�׼��С�ķŵ���ߣ���ķ��ڻ�׼�����ұߣ����ѻ�׼�����м� 
									  2��������� 
									  3�������ұ�
*********************************************************************************************/

void quick_sort(int L,int R) {
	//TODO 1���жϱ߽� 
	if (L>=R) return;
	//TODO 2��ȡLλ��Ϊ��׼����
	int i=L,j=R;
	int mid=L+(R-L)/2;
	int base=a[L]; 	//ȡa[L]Ϊ��׼�� 
	while(i!=j){
		while(a[j]>=base && i<j) //ͣ��ʱ˵�� a[j]<base ����i==j
			j--;
		while(a[i]<=base && i<j) //ͣ��ʱ˵�� a[i]>base ����i==j
			i++;
		swap(a[i],a[j]); //�������� 
	}
	swap(a[L],a[i]); //�ѻ�׼���ŵ��м� 
	
	//TODO 3:�������
	quick_sort(L,i-1);
	//TODO 4:�����ұ� 
	quick_sort(i+1,R);
	return;
}









/*********************************************************************************************
										������
*********************************************************************************************/

void solve() {
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	quick_sort(1,n);
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl; 
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
	while(T--) {
		solve();
	}
	return 0;
}
