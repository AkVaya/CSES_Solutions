#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<pair<ll, ll> > >v;
vector<bool> vis;
vector<ll> mn, mx, routes, dp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector<vector<int> >dp(n+1, vector<int>(32, 0));
    for (int i = 1; i < n+1; ++i)
    {
        cin>>dp[i][0];
    }
    //cout<<"YAHA"<<endl;
    for (int j = 1; j < 32; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    int x, k;
    while(q--){
        cin>>x>>k;
        int y = 0;
        while(k){
            if(k&1)
                x = dp[x][y];
            y++;
            k>>=1;
        }
        cout<<x<<'\n';
    }
    return 0;
}