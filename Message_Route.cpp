#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
vector<vector<int> > v;
vector<int> parent, vis;
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
        v[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(q.size()){
        int s = q.front();
        q.pop();
        for(auto i : v[s]){
            if(!vis[i]){
                parent[i] = s;
                vis[i] = true;
                q.push(i);
            }
            if(i==n){
                while(q.size())
                    q.pop();
            }
        }
    }
    if(!vis[n]){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        vector<int> res;
        int curr = n;
        while(curr!=-1){
            res.push_back(curr);
            curr = parent[curr];
        }
        cout<<res.size()<<'\n';
        reverse(res.begin(), res.end());
        for(auto i : res)
            cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}