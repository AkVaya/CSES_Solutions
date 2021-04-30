#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
ll a[nax],tree[4*nax];
void build(ll curr, ll L, ll R){
   	if(L==R-1){
      	tree[curr] = a[L];
      	return;
   	}
   	ll mid = (L+R)/2;
   	build(2*curr,L,mid);
   	build(2*curr+1,mid,R);
   	tree[curr] = min(tree[2*curr], tree[2*curr+1]);
}
ll query(ll curr, ll qL, ll qR, ll L, ll R){
   	if(qL>=R || qR<=L)
    	return INT_MAX;
   	if(qR>=R && qL<=L)
      	return tree[curr];
   	ll mid = (L+R)/2;
   	ll res = query(2*curr,qL,qR,L,mid);
   	res = min(res, query(2*curr+1,qL,qR,mid,R));
   	return res;
}
void update(ll ind, ll val, ll L, ll R, ll curr){
   	if(ind<L || ind>=R)
    	return;
   	if(L==R-1){
      	tree[curr] = val;
      	a[ind] = val;
      	return;
   	}
   	ll mid = (L+R)/2;
   	update(ind,val,L,mid,2*curr);
   	update(ind,val,mid,R,2*curr+1);
   	tree[curr] = min(tree[2*curr], tree[2*curr+1]);
}
int main(){
   	int n,q;
   	cin>>n>>q;
   	for (int i = 1; i <= n; ++i)
   	{
    	cin>>a[i];
   	}	  
   	build(1,1,n+1);
   	while(q--){
      	int x,y,z;
      	cin>>x>>y>>z;
      	if(x==2){
         	cout<<query(1,y,z+1,1,n+1)<<'\n';
      	}
      	else{
         	update(y,z,1,n+1,1);
      	}
   	}
}