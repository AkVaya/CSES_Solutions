#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<pair<ll, ll> > >v;
vector<ll> dist;
vector<bool> vis;
void dijkstra(int s){
    dist[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >pq;
    pq.push({0, s});
    while(pq.size()){
        s = pq.top().second;
        ll wt = pq.top().first;
        pq.pop();
        if(vis[s])
            continue;
        vis[s] = 1;
        for(auto i : v[s]){
            if(i.second + wt < dist[i.first]){
                dist[i.first] = i.second + wt;
                pq.push({dist[i.first], i.first});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y, z;
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1, false);
    dist.resize(n+1, 1e18);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>z;
        v[x].push_back({y, z});
    }
    dijkstra(1);
    for (int i = 1; i <= n; ++i)
        cout<<dist[i]<<' ';
    cout<<'\n';
    

    return 0;
}