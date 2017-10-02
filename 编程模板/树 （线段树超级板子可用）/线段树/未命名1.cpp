#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>
#include <algorithm>
//#define LL long long
#define LL __int64
#define eps 1e-12
#define PI acos(-1.0)
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 131072;

struct node
{
	int l,r;
	int col;
	int rev;
}tree[maxn*4];

char s1[10],s2[10];
int a[maxn+10];

void build(int v, int l, int r)
{
	tree[v].l = l;
	tree[v].r = r;
	tree[v].col = 0;
	tree[v].rev = 0;
	if(l == r)
		return;
	int mid = (l+r)>>1;
	build(v*2,l,mid);
	build(v*2+1,mid+1,r);
}

void push_down(int v)
{
	if(tree[v].l == tree[v].r)
		return;
	if(tree[v].col != -1) //区间被完全覆盖
	{
		tree[v*2].col = tree[v*2+1].col = tree[v].col; //向下推送，并把自己的col置为-1
		tree[v].col = -1;
		tree[v].rev = 0;
		tree[v*2].rev = tree[v*2+1].rev = 0; //儿子节点也被完全覆盖，因此抹去异或操作
	}
	if(tree[v].rev) //区间没被完全覆盖且需要异或
	{
		if(tree[v*2].col != -1) //儿子节点被完全覆盖，直接异或
			tree[v*2].col ^= 1;
		else tree[v*2].rev ^= 1;//否则rev进行异或。
		if(tree[v*2+1].col != -1)
			tree[v*2+1].col ^= 1;
		else tree[v*2+1].rev ^= 1;
		tree[v].rev = 0;
	}
}

void update(int v, int l, int r, int col)
{
	if(l > r) //l > r的区间忽略不计
		return;
	if(tree[v].l == l && tree[v].r == r)
	{
		if(col == 0 || col == 1)
		{
			tree[v].col = col;
			tree[v].rev = 0;
		}
		else
		{
			if(tree[v].col != -1)
				tree[v].col ^= 1;
			else
				tree[v].rev ^= 1;
		}
		return;
	}
	push_down(v);
	int mid = (tree[v].l + tree[v].r) >> 1;
	if(r <= mid)
		update(v*2,l,r,col);
	else if(l > mid)
		update(v*2+1,l,r,col);
	else
	{
		update(v*2,l,mid,col);
		update(v*2+1,mid+1,r,col);
	}
}

void query(int v)
{
	if(tree[v].l==tree[v].r)
	{
		if (tree[v].col==1) cout<<tree[v].l<<"  ";
		return;
	}
	push_down(v);
	query(v*2);
	query(v*2+1);
}

int main()
{
	freopen("datain.txt","r",stdin);
	build(1,0,maxn);
	int l,r,len;
    memset(a,0,sizeof(a));
	while(~scanf("%s %s",s1,s2))
	{
		l = 0;
		r = 0;
		len = strlen(s2);
		int i;
		for(i = 1; s2[i] >= '0' && s2[i] <= '9'; i++)
			l = l*10 + s2[i]-'0';
		i++;
		for(; s2[i] >= '0' && s2[i] <= '9'; i++)
			r = r*10 + s2[i]-'0';
		if(s2[0] == '[')
			l = l*2;
		else l = l*2+1;
		if(s2[len-1] == ']')
			r = r*2;
		else r = r*2-1;
		
		cout<<l<<"  "<<r<<endl;
		if(s1[0] == 'U')
		{
			update(1,l,r,1);
		}
		else if(s1[0] == 'I')
		{
			update(1,0,l-1,0);
			update(1,r+1,maxn,0);
		}
		else if(s1[0] == 'D')
		{
			update(1,l,r,0);
		}
		else if(s1[0] == 'C')
		{
			update(1,0,l-1,0);
			update(1,r+1,maxn,0);
			update(1,l,r,2); //取反
		}
		else
		{
			update(1,l,r,2);//取反
		}
		query(1);
		cout<<endl;
	}

	return 0;
}
