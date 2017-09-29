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
const int Hash_size=1e4+7;
/*********************************************************************************************
										��ϣO(1)����
*********************************************************************************************/

unsigned int get_Hash(string  str) {
	unsigned int seed=13331;
	unsigned int H=0;
	for (int i=0; str[i]; i++) H=H*seed+str[i];
	return (H & 0x7FFFFFFF)%Hash_size;
}

struct Hash_node {
	vector <string> vis;
} Hash_table[Hash_size];

bool search_Hash(string str) {
	int id=get_Hash(str);
	for (int i=0; i<Hash_table[id].vis.size(); i++)
		if (Hash_table[id].vis[i]==str) return true;
	Hash_table[id].vis.push_back(str);
	return false;
}









/*********************************************************************************************
										������
*********************************************************************************************/

void solve() {
	string str;
	while(cin>>str) {
		if ( search_Hash(str) ) cout<<"yes"<<endl;
		else					cout<<"no"<<endl;
	}
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
