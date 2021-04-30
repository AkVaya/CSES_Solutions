#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int st[nax][25],lg[nax];
int main(){
	int n,q;
	cin>>n>>q;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		st[i][0] = a[i]; 
	}
	lg[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		lg[i] = 1 + lg[i/2];
	}
	for (int j = 1; j < 25; ++j)
		for (int i = 0; i + (1LL<<j) <= n; ++i)
			st[i][j] = min(st[i][j-1],st[i+(1LL<<(j-1))][j-1]);
	while(q--)	{
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		int j = lg[r - l + 1];
		int res = min(st[l][j], st[r - (1LL<<j) + 1][j]);
		cout<<res<<'\n';
	}
	return 0;
}