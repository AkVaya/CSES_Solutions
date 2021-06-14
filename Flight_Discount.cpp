#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<pair<ll, ll> > >v;
vector<ll> dp[2];
vector<bool> vis;
void dijkstra(int s){
    dp[0][s] = dp[1][s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >pq;
    pq.push({0, s});
    while(pq.size()){
        s = pq.top().second;
        // cout<<s<<endl;
        pq.pop();
        if(vis[s])
            continue;
        vis[s] = 1;

        for(auto i : v[s]){
            bool done = false;
            // cout<<i.first<<' '<<i.second<<endl;
            if(i.second + dp[0][s] < dp[0][i.first]){
                dp[0][i.first] = i.second + dp[0][s];
                done = true;
            }
            // cout<<"YAHA"<<endl;
            if(i.second/2 + dp[0][s] < dp[1][i.first]){
                dp[1][i.first] = i.second/2 + dp[0][s];
                done = true;
            }
            // cout<<"YAHA"<<endl;
            if(i.second + dp[1][s] < dp[1][i.first]){
                dp[1][i.first] = i.second + dp[1][s];
                done = true;
            }
            if(done){
                pq.push({dp[1][i.first], i.first});
                pq.push({dp[0][i.first], i.first});
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
    dp[0].resize(n+1, 1e18);
    dp[1].resize(n+1, 1e18);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>z;
        v[x].push_back({y, z});
    }
    dijkstra(1);
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout<<i<<' '<<dp[0][i]<<' '<<dp[1][i]<<endl;
    // }
    cout<<min(dp[0][n], dp[1][n])<<'\n';
    
 
    return 0;
}