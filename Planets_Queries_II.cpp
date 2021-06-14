
#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int M = 1e9 + 7;
const int nax = 2e5 + 69;
vector<vector<int> >child(nax, vector<int>(20, 0));
vector<int>vis, height;
void dfs(int s){
    vis[s] = 1;
    if(!vis[child[s][0]])
        dfs(child[s][0]);
    height[s] = height[child[s][0]] + 1;
}
int lift(int x, int k){
    if(k<0)
        return x;
    int y = 0;
    while(k){
        if(k&1)
            x = child[x][y];
        y++;
        k>>=1;
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    vis.resize(n+1, 0);
    height.resize(n+1, 0);
    for (int i = 1; i < n+1; ++i)
    {
        cin>>child[i][0];
    }
    for (int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    for (int j = 1; j < 20; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            child[i][j] = child[child[i][j-1]][j-1];
        }
    }
    int a, b;
    while(q--){
        cin>>a>>b;
        int cycle = lift(a, height[a]);
        if(lift(a, height[a] - height[b]) == b)
            cout<<height[a] - height[b]<<'\n';
        else if(lift(cycle, height[cycle] - height[b])==b)
            cout<<height[cycle] + height[a] - height[b]<<'\n';
        else
            cout<<"-1\n";
    }
    return 0;
}