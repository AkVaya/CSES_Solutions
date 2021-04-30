#include<bits/stdc++.h>
using namespace std;
const int nax = 1e3+69;
vector<vector<int> > v;
vector<bool> vis;
void dfs(int s){
    vis[s] = true;
    for(auto i : v[s])
        if(!vis[i])
            dfs(i);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, m, x, y;   
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1, false);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> res;
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            res.push_back(i);
            dfs(i);
        }
    }
    cout<<res.size()-1<<'\n';
    for (int i = 1; i < res.size(); ++i)
    {
        cout<<res[i]<<' '<<res[i-1]<<'\n';
    }
    return 0;
}