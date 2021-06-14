#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
const ll nax = 2e5 + 69;
vector<vector<int> >v, rv;
vector<set<int> >scc;
vector<bool> vis1, vis;
vector<ll> temp, dp;
ll val[nax];
void dfs(int s, int type){
    if(type)
        temp.push_back(s);
    vis[s] = true;
    for(auto i : (type ? rv[s] : v[s]))
        if(!vis[i])
            dfs(i, type);
    if(!type)
        temp.push_back(s);
}
ll fun(int s, ll &mx){
    ll curr = 0;
    vis[s] = true;
    for(auto i : scc[s])
        if(!vis[i])
            curr = max(curr, fun(i, mx));
        else curr = max(dp[i], curr);
    mx = max(mx, curr + val[s]);
    // cout<<s<<' '<<curr<<endl;
    return dp[s] = curr + val[s];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, m, y, z;
    cin>>n>>m;
    x = 0;
    for (int i = 1; i <= n; ++i){
        cin>>val[i];
    }
    v.resize(n+1);scc.resize(n+1);
    rv.resize(n+1);
    dp.resize(n+1, 0);
    vis.resize(n+1, 0);
    for (int i = 1; i <= m; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
        rv[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i])
            dfs(i, 0);
    }
    vector<ll> topo = temp;
    reverse(topo.begin(), topo.end());
    fill(vis.begin(), vis.end(), false);
    
    vector<int> head(n+1, 0);
    for(auto i : topo){
        if(!vis[i]){
            temp.clear();
            dfs(i, 1);
            // cout<<i<<":";
            for(auto i : temp){
                // cout<<i<<' ';
                head[i] = temp[0];
                if(i!=temp[0])
                    val[temp[0]] += val[i];
            }
            dp[temp[0]] = val[temp[0]];
            // cout<<endl;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for(auto j : v[i]){
            if(head[i]!=head[j]){
                scc[head[i]].insert(head[j]);
            }
        }
    }
    ll res = 0;
    fill(vis.begin(), vis.end(), false);
    for (int i = 1; i <= n; ++i)
    {
        if(scc[i].size() && !vis[i])
            fun(i, res);
    }
    cout<<res<<'\n';
    return 0;
}