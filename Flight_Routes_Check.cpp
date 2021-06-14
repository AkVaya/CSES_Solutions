#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<int> >v, rv, components;
vector<bool> vis1, vis;
void dfs(int s, int type){
    if(type)
        vis1[s] = true;
    else
        vis[s] = true;
    for(auto i : (type ? rv[s] : v[s]))
        if((type ? !vis1[i] : !vis[i]))
            dfs(i, type);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, m, y, z;
    cin>>n>>m;
    v.resize(n+1);
    rv.resize(n+1);
    vis.resize(n+1, false);vis1.resize(n+1, false);
    vector<int> res(n+1, 0);
    for (int i = 1; i <= m; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
        rv[y].push_back(x);
    }
    dfs(1, 0);
    dfs(1, 1);
    bool check = false;
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i] || !vis1[i]){
            check = true;
            break;
        }
    }
    if(!check){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
        bool check = false;
        for (int i = 1; i <= n; ++i)
        {
            if(!vis[i]){
                check = true;
                cout<<1<<' '<<i<<'\n';
                break;
            }
        }
        if(!check){
            for (int i = 1; i <= n; ++i)
            {
                if(!vis1[i]){
                    check = true;
                    cout<<i<<' '<<1<<'\n';
                    break;
                }
            }
        }
    }

    return 0;
}