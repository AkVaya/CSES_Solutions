#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
const ll nax = 2e5 + 69;
vector<vector<int> >v;
ll dp[nax], height[nax];
int dfs1(int s, int p){
    int mx = 0;
    for(auto i : v[s]){
        if(i!=p)
            mx = max(mx, 1 + dfs1(i, s));
    }
    return height[s] = mx;
}
void dfs2(int s, int p, int pAns){
    vector<int> pref, suff;
    // cout<<s<<' '<<pAns<<endl;
    for (auto i : v[s])
    {
        if(i==p)
            continue;
        pref.push_back(height[i]);
        suff.push_back(height[i]);
    }
    for (int i = 1; i < pref.size(); ++i)
        pref[i] = max(pref[i], pref[i-1]);
    for (int i = pref.size() - 2; i >= 0; --i)
        suff[i] = max(suff[i], suff[i+1]);
    int mx = 0, cnt = 0;
    for(auto i : v[s]){
        if(i==p)
            continue;
        int val1 = (cnt ? pref[cnt-1] : -1);
        int val2 = (cnt+1<suff.size() ? suff[cnt+1] : -1);
        // cout<<"val1 :"<<val1<<' '<<val2<<endl;
        int curr = max(max(val1, val2), pAns)+ 1;
        dfs2(i, s, curr);
        cnt++;
    }
    dp[s] = 1 + max(pAns, (suff.size() ? suff[0] : -1));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin>>n;
    v.resize(n+1);
    for (int i = 1; i < n; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    // cout<<"YAHA"<<endl;
    dfs1(1, -1);
    dfs2(1, -1, -1);
    for (int i = 1; i <= n; ++i)
    {
        cout<<dp[i]<<' ';
    }
    return 0;
}