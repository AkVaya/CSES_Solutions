#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 1;
const int M = 1e9 + 7;
long long binpow(long long a,long long b){
	long long res = 1;
	while(b){
		if(b&1)
			res = (res*a)%M;
		a = (a * a)%M;
		b>>=1;
	}
	return res;
}
void mult(long long &a,long long b){
	a*=b;
	a%=M;
}
int main(){
	vector<long long> fact(nax,1);
	for (int i = 2; i < nax; ++i)
	{
		fact[i] = (fact[i-1] * i)%M;
	}
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		long long ans = fact[a];
		mult(ans,binpow(fact[b],M-2));
		mult(ans,binpow(fact[a-b],M-2));
		cout<<ans<<'\n';
	}

	return 0;
} 