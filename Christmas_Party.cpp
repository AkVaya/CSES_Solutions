#include<bits/stdc++.h>
using namespace std;
const int nax = 2e6 + 1;
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
void sub(long long &a,long long b){
	a-=b;
	if(a<=0)
		a+=M;
	a%=M;
}
void add(long long &a,long long b){
	a+=b;
	a%=M;
}
int main(){
	vector<long long> fact(nax,1),cnt(26,0);
	for (int i = 2; i < nax; ++i)
	{
		fact[i] = (fact[i-1] * i)%M;
	} 
	long long n,m;
	cin>>n;
	long long ans = fact[n],temp = 0;
	for (int i = 2; i <= n; ++i)
	{
		if(i%2)
			sub(temp,binpow(fact[i],M-2));
		else
			add(temp,binpow(fact[i],M-2));
	}
	mult(ans,temp);
	cout<<ans<<'\n';
	return 0;
} 