#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
struct FenwickTree
{
	vector<ll> bit;
	int n;
	
	FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<ll> a)
        : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            range_add(i, i, a[i]);
    }
    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    void range_add(int l, int r, int val) {
	    add(l, val);
	    add(r + 1, -val);
	}
	ll point_query(int idx) {
	    ll ret = 0;
	    for (++idx; idx > 0; idx -= idx & -idx)
	        ret += bit[idx];
	    return ret;
	}
};
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, q;
	cin>>n>>q;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	FenwickTree bit = FenwickTree(v);
	int x, y, z, val;
	while(q--){
		cin>>x>>y;
		if(x==2){
			cout<<bit.point_query(y-1)<<'\n';
			continue;
		}		
		cin>>z>>val;
		bit.range_add(y-1, z-1, val);
	}
	return 0;
}