#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<int> >v;
vector<ll> vis, dp;
int n;
void dfs(int s){
    vis[s] = 1;
    if(s==n){
        vis[s] = 2;
        dp[s] = 1;
        return;
    }
    dp[s] = 0;
    for(auto i : v[s]){
        if(vis[i]==0)
            dfs(i);
        dp[s] = (dp[s] + dp[i])%M;
    }
    vis[s] = 2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, x, y;
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1, 0);
    dp.resize(n+1, 0);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
    dfs(1);
    cout<<dp[1]<<'\n';

    return 0;
}