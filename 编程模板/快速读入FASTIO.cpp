#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;

/***********************************************************************************
                                        ��������
************************************************************************************/
int scan() {
	int res=0;
	bool flag=false;
	int ch;
	if ( ( ch=getchar() ) == '-') flag=true;
	else if (ch>='0' && ch<='9') res=ch-'0';
	while( (ch=getchar()) >='0' && ch<='9' )
		res=res*10+ch-'0';
	return flag ? -res : res;
}

/***********************************************************************************
                                    	�������
************************************************************************************/
void Out(int x) {
	if (x>9) Out(x/10);
	putchar(x%10 + '0' );
}

/***********************************************************************************
                                     �и��������
************************************************************************************/
void print(int x) {
	if (x<0) {
		putchar('-');
		Out(-x);
	} else
		Out(x);
}



/*************************************************************************************************************************
                                                            ������
**************************************************************************************************************************/
void solve() {
	int n,m;
	n=scan();
	m=scan();
	int a[n];
	for (int i=0; i<n; i++) {
		a[i]=scan();
		print(a[i]);
		putchar(' ');
	}
	putchar('\n');
	int left[m],right[m];
	for (int i=0;i<m;i++){
		left[i]=scan();
		right[i]=scan();
		print(left[i]);
		putchar(' ');
		print(right[i]);
		putchar('\n'); 
	}
	putchar('\n');
	putchar('\n');
}

int main() {
	freopen("FASTIO�������.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}

