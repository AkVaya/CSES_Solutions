#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
ll st[nax][25];
int main(){
	ll n,q;
	cin>>n>>q;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		st[i][0] = a[i]; 
	}
	for (int j = 1; j < 25; ++j)
		for (int i = 0; i + (1LL<<j) <= n; ++i){
			st[i][j] = st[i][j-1] + st[i+(1<<(j-1))][j-1];
		}	
	while(q--)	{
		ll sum = 0,l,r;
		cin>>l>>r;
		l--;
		r--;
		for (int j = 24; j >= 0; --j)
			if(l + (1LL<<j) - 1<=r){
				sum += st[l][j];
				l += (1LL<<j);
			}
		cout<<sum<<'\n';
	}
	return 0;
}