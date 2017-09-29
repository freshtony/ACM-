#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath> 
using namespace std;
char s[1000],b[1000];
int num;
int creat(int begin,int end,int root)
{
	if (end==begin) 
	{
		if (s[begin-1]=='1') {b[root]='I'; return 1;}
		else {b[root]='B'; return 0;}
	}
	else
	{
		int vis1=creat(begin,(begin+end)/2,root*2);
		int vis2=creat((begin+end)/2+1,end,root*2+1);
		if (vis1==1 && vis2==1) {b[root]='I'; return 1; }
		if (vis1==2 || vis2==2 || (vis1+vis2)==1 )   {b[root]='F'; return 2;}
		if (vis1==0 && vis2==0) { b[root]='B'; return 0;	}
		
	}
}
void print(int pos)
{
	if ( (pos*2) <= num ) print(pos*2);
	if ( (pos*2+1)<=num) print(pos*2+1);
	printf("%c",b[pos]);
	return ;
}
int main()
{
	int T,len,n,i;
	freopen("data.txt","r",stdin);
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",&s);
		num=pow(2,n);
		creat(1,num,1);
		num=num*2-1;
		print(1);
		cout<<endl;
	}
	
	return 0;
}
