#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<int> >v;
vector<int> vis;
int n;
bool dfs(int s, vector<int>& res){
    vis[s] = 1;
    for(auto i : v[s]){
        // cout<<s<<' '<<i<<' '<<vis[i]<<endl;
        if(vis[i]==0){
            if(dfs(i, res))
                return true;
        }
        else if(vis[i]==1){
            // cout<<"YAHA"<<endl;
            return true;
        }
    }
    res.push_back(s);
    vis[s] = 2;
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, x, y;
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1, 0);
    vector<int> res;
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
    bool cycle = false;
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i])
            cycle |= dfs(i, res);
    }
    // cout<<cycle<<endl;
    if(!cycle){
        reverse(res.begin(), res.end());
        for(auto i : res)
            cout<<i<<' ';
    }
    else
        cout<<"IMPOSSIBLE";
    cout<<'\n';

    return 0;
}