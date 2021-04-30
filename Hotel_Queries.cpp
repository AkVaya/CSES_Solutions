#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 69;
int a[nax],tree[4*nax];
void build(int curr, int L, int R){
   	if(L==R-1){
      	tree[curr] = a[L];
      	return;
   	}
   	int mid = (L+R)/2;
   	build(2*curr,L,mid);
   	build(2*curr+1,mid,R);
   	tree[curr] = max(tree[2*curr], tree[2*curr+1]);
}
int query(int curr, int qL, int qR, int L, int R){
   	if(qL>R || qR<=L)
    	return 0;
   	if(qR>=R && qL<=L)
      	return tree[curr];
   	int mid = (L+R)/2;
   	int res = query(2*curr,qL,qR,L,mid);
   	res = max(res, query(2*curr+1,qL,qR,mid,R));
   	return res;
}
void update(int ind, int val, int L, int R, int curr){
   	if(ind<L || ind>=R)
    	return;
   	if(L==R-1){
      	tree[curr] = val;
      	a[ind] = val;
      	return;
   	}
   	int mid = (L+R)/2;
   	update(ind,val,L,mid,2*curr);
   	update(ind,val,mid,R,2*curr+1);
   	tree[curr] = max(tree[2*curr], tree[2*curr+1]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
   	int n,q;
   	cin>>n>>q;
   	for (int i = 1; i <= n; ++i)
   	{
    	cin>>a[i];
   	}	  
   	build(1,1,n+1);
   	//cout<<tree[1]<<endl;
   	while(q--){
      	int x;
      	cin>>x;
      	int l = 1, r = n;
      	while(l<=r){
      		int mid = (l+r)/2;
      		if(query(1,1,mid+1,1,n+1)>=x)
      			r = mid - 1;
      		else
      			l = mid + 1;
      	}
      	if(r==n){
      		cout<<0<<' ';
      		continue;
      	}
      	int val = a[r+1];
      	cout<<r+1<<' ';
        update(r+1,val-x,1,n+1,1);
   	}
   	return 0;
}