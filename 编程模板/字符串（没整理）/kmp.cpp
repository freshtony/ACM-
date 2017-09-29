#include <iostream>
#include <cstring>
using namespace std;
int nxt[10000+5];
int original_str[1000000+5],son_str[10000+5];
int n,m;
void getnxt()
{
	int i,j;
	nxt[1]=0;
	for (i=2;i<=m;i++)
	{
		j=nxt[i-1];
		while ( j>0 && son_str[j+1]!=son_str[i])
		{
			j=nxt[j];
		}
		if ( son_str[i] == son_str[j+1] ) nxt[i]=j+1;
		else nxt[i]=0;
	}
}
int kmp(){
	int o_i=1, s_i=1;
	while ( o_i<=n && s_i <=m )
	{
		if (original_str[o_i] == son_str[s_i])
		{
			o_i++;
			s_i++;
		}
		else
		{
			if (s_i==1) o_i++;
			else s_i=nxt[s_i-1]+1;
		}
	}
	return (s_i==(m+1)) ? (o_i-m):-1;
}
void init(){
	memset(nxt,0,sizeof(nxt));
}
int main()
{
	freopen("data.txt","r",stdin);
	int T;
	cin>>T;
	while (T--)
	{
		init();
		cin>>n>>m;
		for (int i=1;i<=n;i++) scanf("%d",&original_str[i]);
		for (int i=1;i<=m;i++) scanf("%d",&son_str[i]);
		if (n<m) printf("-1\n");
		else
		{
			getnxt();
			printf("%d\n",kmp());
		}
	}
}
