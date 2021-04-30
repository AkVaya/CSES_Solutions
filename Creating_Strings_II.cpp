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
	vector<long long> fact(nax,1),cnt(26,0);
	for (int i = 2; i < nax; ++i)
	{
		fact[i] = (fact[i-1] * i)%M;
	} 
	string s;
	cin>>s;
	long long ans = 1;
	for(auto i : s)
		cnt[i-'a']++;
	long long curr = s.length();
	for(auto i : cnt){
		long long temp = fact[curr];
		mult(temp,binpow(fact[i],M-2));
		mult(temp,binpow(fact[curr-i],M-2));
		curr -= i;
		mult(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
} 