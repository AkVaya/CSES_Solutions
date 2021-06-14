#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<pair<ll, ll> > >v;
vector<bool> vis;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y, z, k;
    cin>>n>>m>>k;
    priority_queue<ll> best[n+1];
    v.resize(n+1);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>z;
        v[x].push_back({y, z});
    }
    int s = 1;
    best[1].push(0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >pq;
    pq.push({0, s});
    while(pq.size()){
        s = pq.top().second;
        ll wt = pq.top().first;
        pq.pop();
        if(wt > best[s].top())
            continue;
        for(auto i : v[s]){
            ll curr = i.second + wt;
            if(best[i.first].size()<k){
                best[i.first].push(curr);
                pq.push({curr, i.first});
            }
            else if(curr < best[i.first].top()){
                best[i.first].pop();
                best[i.first].push(curr);
                pq.push({curr, i.first});
            }
        }
    }
    vector<ll> res;
    while(best[n].size()){
        res.push_back(best[n].top());
        best[n].pop();
    }
    reverse(res.begin(), res.end());
    for(auto i : res)
        cout<<i<<' ';
    cout<<'\n';
    return 0;
}