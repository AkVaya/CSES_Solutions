#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
const ll nax = 2e5 + 69;
vector<vector<int> >v;
vector<int> dp;
int dfs(int s){
    dp[s] = 0;
    int cnt = 1;
    for(auto i : v[s])
            cnt += dfs(i);
    dp[s] = cnt-1;
    // cout<<s<<' '<<cnt<<endl;
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin>>n;
    v.resize(n+1);
    dp.resize(n+1);
    for (int i = 1; i < n; ++i)
    {
        cin>>x;
        v[x].push_back(i+1);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
        cout<<dp[i]<<' ';
    cout<<'\n';
    return 0;
}