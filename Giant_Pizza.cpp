#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
const ll nax = 2e5 + 69;
vector<vector<int> >v, rv;
vector<bool> vis1, vis;
vector<int> temp, component;
int k = 0;
void dfs1(int s){
    vis[s] = true;
    for(auto i : v[s])
        if(!vis[i])
            dfs1(i);
    temp.push_back(s);
} 
void dfs2(int s){
    vis[s] = true;
    component[s] = k;
    for(auto i : rv[s])
        if(!vis[i])
            dfs2(i);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, m, y, z;
    cin>>n>>m;
    // 2 sat ka problem hai
    v.resize(2*m+5);
    rv.resize(2*m+5);
    vis.resize(2*m+5, 0);
    component.resize(2*m+5, 0);
    for (int i = 1; i <= n; ++i)
    {
        char a, b;
        cin>>a>>x>>b>>y;
        if(a=='-')
            x = 2*m - x + 1; // ulta
        if(b=='-')
            y = 2*m - y + 1;
        v[2*m - x  + 1].push_back(y);v[2*m - y  + 1].push_back(x);
        rv[x].push_back(2*m - y + 1);rv[y].push_back(2*m - x  + 1);
    }
    // cout<<"YAHA"<<endl;
    for (int i = 1; i <= 2*m; ++i)
    {
        if(!vis[i])
            dfs1(i);
    }
    // cout<<"YAHA"<<endl;
    fill(vis.begin(), vis.end(), false);
    vector<int> topo = temp;
    reverse(topo.begin(), topo.end());
    for(auto i : topo){
        if(!vis[i]){
            dfs2(i);
            k++;
        }
    }
    vector<int> ans(m+1, 0);
    for (int i = 1; i <= m; i++)
    {
        if(component[i]==component[2*m-i+1]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        ans[i] = (component[i] > component[2*m-i+1]);
    }
    for (int i = 1; i <= m; ++i)
    {
        cout<<(ans[i] ? '+' : '-')<<' ';
    }
    cout<<'\n';
    return 0;
}