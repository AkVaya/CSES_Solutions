#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
const ll nax = 2e5 + 69;
vector<vector<int> >v;
ll up[nax][20], lvl[nax];
void dfs(int s, int p){
    for(auto i : v[s]){
        if(i==p)
            continue;
        lvl[i] = 1 + lvl[s];
        dfs(i, s);
    }
}
int lift(int x, int k){
    int y = 0;
    while(k){
        if(k&1)
            x = up[x][y];
        y++;
        k>>=1;
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, q, n;
    cin>>n>>q;
    v.resize(n+1);
    for (int i = 2; i <= n; ++i)
    {
        cin>>x;
        v[x].push_back(i);
        up[i][0] = x;
    }
    dfs(1, -1);
    for (int j = 1; j < 20; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    while(q--){
        cin>>x>>y;
        if(lvl[x]<y)
            cout<<-1<<'\n';
        else{
            cout<<lift(x, y)<<'\n';
        }
    }
    return 0;
}