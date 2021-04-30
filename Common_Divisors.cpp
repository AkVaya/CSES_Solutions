#include<bits/stdc++.h>
using namespace std;
const long long nax = 1e6 + 1;
vector<int> cnt(nax,0);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int a[n],ans=0,mx=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		cnt[a[i]]++;
		mx= max(a[i],mx);
	}
	int temp = mx;
	while(temp>1){
		int curr = temp,count = 0;
		while(curr<=mx){
			if(cnt[curr]){
				count+=cnt[curr];
			}
			if(count>=2){
				ans = temp;
				break;
			}
			curr+=temp;
		}
		temp--;
		if(ans)
			break;
	}
	if(!ans)
		ans=1;
	cout<<ans<<endl;
	return 0;
}