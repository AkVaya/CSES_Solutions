#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
const ll nax = 569;
struct edges{
    int u, v;
    ll wt;
};
vector<ll> dp;
vector<edges> e;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    ll z;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>z;
        e.push_back({x, y, z});
    }
    vector<ll> dist(n+1, 1e18), parent(n+1, -1);
    x = -1;
    dist[1] = 0;
    for (int a = 0; a < n; ++a)
    {
        x = -1;
        for(auto i : e){
            if(dist[i.u] + i.wt < dist[i.v]){
                dist[i.v] = dist[i.u] + i.wt;
                x = i.v;    
                parent[i.v] = i.u;
            }
        }
        // cout<<x<<endl;
    }
    if(x==-1)
        cout<<"NO\n";
    else{
        cout<<"YES\n";
        for (int i = 0; i < n; ++i)
            x = parent[x];
        vector<int> res;
        int a = x;
        while(a!=x || !res.size()){
            res.push_back(a);
            a = parent[a];
        }
        res.push_back(a);
        reverse(res.begin(), res.end());
        for(auto i : res)
            cout<<i<<' ';
        cout<<'\n';
    }
 
    return 0;
}