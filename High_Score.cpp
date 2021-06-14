#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
const ll nax = 569;
struct edges{
    int u, v;
    ll wt;
};
vector<vector<int> >v[2];
vector<edges> e;
vector<bool> vis[2];
void dfs(int s, int x){
    vis[x][s] = true;
    for(auto i : v[x][s])
        if(!vis[x][i])
            dfs(i, x);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    ll z;
    cin>>n>>m;
    v[0].resize(n+1);
    v[1].resize(n+1);
    vis[0].resize(n+1, false);
    vis[1].resize(n+1, false);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>z;
        e.push_back({x, y, z});
        v[0][x].push_back(y);
        v[1][y].push_back(x);
    }
    dfs(1, 0);
    dfs(n, 1);
    vector<ll> dist(n+1, LLONG_MIN);
    x = -1;
    dist[1] = 0;
    for (int a = 0; a < n; ++a)
    {
        x = -1;
        for(auto i : e){
            if(dist[i.u]==LLONG_MIN)
                continue;
            if(dist[i.u] + i.wt > dist[i.v]){
                dist[i.v] = dist[i.u] + i.wt;
                if(vis[0][i.v] && vis[1][i.v])
                    x = i.v;
            }
        }
    }
    if(x==-1)
        cout<<dist[n]<<'\n';
    else
        cout<<"-1\n";

    return 0;
}