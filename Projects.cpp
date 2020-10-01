#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<unordered_map>
#include<vector>
#include<bitset>
#include<iomanip>
#include<queue>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
//#define endl '\n'
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
typedef long long ll ;
const ll M =1e9+7;
const ll nax=5e3+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>; 
int n;
vector<pair<ll,pii> > v;
vector<ll> finish,dp;
void solve(){
	int x,y,z;
	cin>>n;
	v.resize(n+1);
	finish.resize(n+1);
	dp.resize(n+1);
	for (int i = 1; i <= n; ++i)
	{
		cin>>v[i].second.first>>v[i].first>>v[i].second.second;
	}
	sort(v.begin()+1, v.end());
	for (int i = 1; i <= n; ++i)
	{
		finish[i]=v[i].first;
	}
	dp[0]=0;
	for (int i = 1; i <= n; ++i)
	{
		auto it = lower_bound(finish.begin()+1,finish.end(),v[i].second.first);
		ll ind = -1;
		if(it==finish.end())
			ind = 0;
		else{
			--it;
			ind = distance(finish.begin()+1,it)+1;
		}
		dp[i] = max(dp[i-1],dp[ind]+v[i].second.second);
		//cout<<dp[i]<<' '<<ind<<endl;
	}
	cout<<dp[n]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}