#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int nax = 2e5 + 69;
vector<vector<int> >v;
int up[nax][21];
vector<int> tin, tout;
int timer = 0;
void dfs(int s, int p){
    tin[s] = ++timer;
    up[s][0] = p;
    for (int i = 1; i < 21; ++i)
    {
        up[s][i] = up[up[s][i-1]][i-1];
    }
    for(auto i : v[s]){
        if(i==p)
            continue;
        dfs(i, s);
    }
    tout[s] = ++timer;
}
bool ancestor(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int u, int v)
{
    // cout<<u<<' '<<v<<":\n";
    if (ancestor(u, v))
        return u;
    else if (ancestor(v, u))
        return v;
    for (int i = 20; i >= 0; --i) {
        if (!ancestor(up[u][i], v))
            u = up[u][i];
        // cout<<i<<' '<<u<<endl;
    }
    return up[u][0];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y, q;
    cin>>n>>q;
    v.resize(n+1);
    tin.resize(n+1, -1);
    tout.resize(n+1, INT_MAX);
    for (int i = 2; i <= n; ++i)
    {
        cin>>x;
        v[x].push_back(i);
    }
    // cout<<"debug "<<endl;
    dfs(1, 1);
    while(q--){
        cin>>x>>y;
        if(x==1 || y==1)
            cout<<1<<'\n';
        else
            cout<<lca(x, y)<<'\n';
    }
    return 0;
}