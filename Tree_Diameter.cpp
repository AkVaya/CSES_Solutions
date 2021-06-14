#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
const ll nax = 2e5 + 69;
vector<vector<int> >v;
vector<int> dp;
void dfs(int s, int p, int curr){
    dp[s] = max(curr, dp[s]);
    for(auto i : v[s])
        if(i!=p)
            dfs(i, s, curr + 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin>>n;
    v.resize(n+1);
    dp.resize(n+1, 0);
    for (int i = 1; i < n; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int mx = 1;
    dfs(1, -1, 0);
    for (int i = 1; i <= n; ++i)
    {
        // cout<<i<<' '<<dp[i]<<endl;
        if(dp[i]>dp[mx])
            mx = i;
    }
    for (int i = 0; i < n+1; ++i)
        dp[i] = 0;
    // cout<<mx<<endl;
    dfs(mx, -1, 0);
    cout<<(*max_element(dp.begin(), dp.end()))<<'\n';
    return 0;
}