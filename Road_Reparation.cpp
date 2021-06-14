#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<pair<ll,ll> > >v;
vector<bool> vis;
ll mst(int s){
    ll res = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq;
    pq.push({0,s});
    while(pq.size()){
        ll curr = pq.top().first;
        int s = pq.top().second;
        pq.pop();
        if(vis[s])
            continue;
        vis[s] = true;
        res += curr;
        for(auto i : v[s]){
            if(vis[i.first])
                continue;
            else{
                pq.push({i.second, i.first});
            }
        }
    }
    return res;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, m, y, z;
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1, 0);
    for (int i = 1; i <= m; ++i)
    {
        cin>>x>>y>>z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    ll res = mst(1);
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    cout<<res<<'\n';
    return 0;
}