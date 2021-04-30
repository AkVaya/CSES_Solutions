#include<bits/stdc++.h>
using namespace std;
const long long nax = 1e6 + 1;
vector<long long> spd(nax,1);
void sieve(){
	for (int i = 0; i < nax; ++i)
		if(i%2)
			spd[i] = i;
		else
			spd[i] = 2;
	for (long long i = 3; i < nax; i+=2)
		if(spd[i]==i)
			for (long long j = i*i; j < nax; j+=i)
				if(spd[j]==j)
					spd[j]=i;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	sieve();
	cin>>t;
	long long n;
	while(t--){
		cin>>n;
		long long ans = 1,curr,cnt;
		while(n>1){
			curr = spd[n];
			cnt = 1;
			while(curr==spd[n]){
				n/=curr;
				cnt++;
			}
			ans*=cnt;
		}
		cout<<ans<<'\n';
	}
	return 0;
}