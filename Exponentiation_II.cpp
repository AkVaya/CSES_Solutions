#include<bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
long long binpow(long long a,long long b,long long m=M){
	long long res = 1;
	while(b){
		if(b&1)
			res = (res * a)%m;
		a = (a * a)%m;
		b>>=1;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	long long a,b,c;
	while(t--){
		cin>>a>>b>>c;
		cout<<binpow(a,binpow(b,c,M-1))<<'\n';
	}
	return 0;
}