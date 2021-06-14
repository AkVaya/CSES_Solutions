#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
const ll nax = 2e5 + 69;
vector<vector<int> >v;
ll res[nax], cnt[nax], subTree[nax], n;
void dfs1(int s, int p){
    cnt[s] = 1;
    subTree[s] = 0;
    for(auto i : v[s]){
        if(i==p)
            continue;
        dfs1(i, s);
        cnt[s] += cnt[i];
        subTree[s] += (subTree[i] + cnt[i]);
    }
}
void dfs2(int s, int p, ll pAns){
    res[s] += subTree[s] + pAns + n - cnt[s];
    for(auto i : v[s]){
        if(i==p)
            continue;
        ll val = res[s] - subTree[i] - cnt[i];
        dfs2(i, s, val);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y;
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
    dfs2(1, -1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cout<<res[i]<<' ';
    }
    return 0;
}