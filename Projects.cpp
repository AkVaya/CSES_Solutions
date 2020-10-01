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
struct Project
{
	int st,end,val;
};
bool cmp(Project &p1,Project &p2){
	return p1.end < p2.end;
}
int n;
ll bin_search(ll val, vector<ll> &endpts){
	auto it = lower_bound(endpts.begin()+1, endpts.end(),val);
	if(it == endpts.end())
		return 0;
	else{
		return distance(endpts.begin()+1,it);
	}
}
void solve(){
	int x,y,z;
	cin>>n;
	vector<Project> v(n+1);
	vector<ll> dp(n+1,0);
	vector<ll> endpts(n+1);
	for (int i = 1; i <= n; ++i)
	{
		cin>>v[i].st>>v[i].end>>v[i].val;
	}
	sort(v.begin()+1, v.end(),cmp);
	for (int i = 1; i <= n; ++i)
	{
		endpts[i]=v[i].end;
	}
	dp[0]=0;
	for (int i = 1; i <= n; ++i)
	{
		ll ind = bin_search(v[i].st,endpts);
		//if()
		dp[i] = max(dp[i-1], v[i].val + dp[ind]);
		//cout<<i<<' '<<ind<<' '<<dp[i]<<endl;
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