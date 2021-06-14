#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<int> >v, rv, components;
vector<int> temp;
vector<bool> vis;
void dfs(int s, int type){
    vis[s] = true;
    if(type)
        temp.push_back(s);
    for(auto i : (type ? rv[s] : v[s]))
        if(!vis[i])
            dfs(i, type);
    if(!type)
        temp.push_back(s);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, m, y, z;
    cin>>n>>m;
    v.resize(n+1);
    rv.resize(n+1);
    vis.resize(n+1, 0);
    vector<int> res(n+1, 0);
    for (int i = 1; i <= m; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
        rv[y].push_back(x);
    }
    z = 1;
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            dfs(i, 0);
        }
    }
    reverse(temp.begin(), temp.end());
    // cout<<"YAHA"<<endl;
    vector<int> order = temp;
    temp.clear();
    fill(vis.begin(), vis.end(), false);
    for(auto i : order){
        if(!vis[i]){
            dfs(i, 1);
            for(auto x : temp){
                // cout<<i<<endl;
                res[x] = z;
            }
            z++;
            temp.clear();
        }
    }   
    cout<<z-1<<'\n';
    for (int i = 1; i <= n; ++i)
    {
        cout<<res[i]<<' ';
    }
    cout<<'\n';

    return 0;
}