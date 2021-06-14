#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<pair<ll, ll> > >v;
vector<bool> vis;
vector<ll> mn, mx, routes, dp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y, z, k;
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1, false);
    mx.resize(n+1, 0);mn.resize(n+1, 0);
    routes.resize(n+1, 0);dp.resize(n+1, LLONG_MAX);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>z;
        v[x].push_back({y, z});
    }
    int s = 1;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >pq;
    pq.push({0, s});
    routes[1] = 1;
    dp[1] = 0;
    while(pq.size()){
        s = pq.top().second;
        pq.pop();
        if(vis[s])
            continue;
        vis[s] = 1;
        for(auto i : v[s]){
            if(dp[i.first]==LLONG_MAX || dp[i.first] > dp[s] + i.second){
                dp[i.first] = dp[s] + i.second;
                routes[i.first] = routes[s];
                mn[i.first] = mn[s] + 1;
                mx[i.first] = mx[s] + 1;
                pq.push({dp[i.first], i.first});
            }
            else if(dp[i.first]==dp[s]+i.second){
                routes[i.first] += routes[s];
                routes[i.first]%=M;
                mn[i.first] = min(mn[i.first], mn[s] + 1);
                mx[i.first] = max(mx[i.first], mx[s] + 1);
                pq.push({dp[i.first], i.first});
            }
        }
    }
    cout<<dp[n]<<' '<<routes[n]<<' '<<mn[n]<<' '<<mx[n]<<'\n'; 
    
    return 0;
}