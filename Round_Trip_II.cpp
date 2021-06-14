#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
vector<vector<int> > v;
vector<int> parent, vis;
bool dfs(int s, int &start, int &end){
    vis[s] = 1;
    for(auto i : v[s]){
        if(vis[i]==1){
            start = i;
            end = s;
            return true;
        }
        else if(vis[i]==0){
            parent[i] = s;
            if(dfs(i, start, end))
                return true;
        }
    }
    vis[s] = 2;
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    cin>>n>>m;
    v.resize(n+1);
    parent.resize(n+1, -1);
    vis.resize(n+1, 0);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
    int start, end;
    bool check = false;
    for (int i = 1; i <= n && !check; ++i)
    {
        if(!vis[i])
            check |= dfs(i, start, end);
    }
    if(!check){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        vector<int> res;
        res.push_back(start);
        while(end!=start && end!=-1){
            res.push_back(end);
            end = parent[end];
        }
        res.push_back(start); 
        cout<<res.size()<<'\n';
        reverse(res.begin(), res.end());
        for(auto i : res)
            cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}