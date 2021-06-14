#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e3 + 69;
vector<vector<int> >v;
vector<int> vis;
int n;
vector<int> nxt, dp;
void dfs(int s){
    vis[s] = 1;
    if(s==n){
        vis[s] = 2;
        dp[s] = 1;
        return;
    }
    for(auto i : v[s]){
        if(vis[i]==0){
            dfs(i);
        }
        if(dp[i]==-1)
            continue;
        if(dp[s]<1 + dp[i]){
            dp[s] = 1 + dp[i];
            nxt[s] = i;
        }
    }
    vis[s] = 2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, x, y;
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1, 0);
    nxt.resize(n+1, -1);
    dp.resize(n+1, -1);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
    dfs(1);
    if(dp[1]==-1)
        cout<<"IMPOSSIBLE\n";
    else{
        cout<<dp[1]<<'\n';
        x = 1;
        while(x!=n){
            cout<<x<<' ';
            x = nxt[x];
        }
        cout<<n<<'\n';
    }

    return 0;
}