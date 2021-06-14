#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<vector<int> >v;
vector<int> vis, dp;
int cnt = 0;
deque<int> dq;
void dfs(int s){
    dq.push_back(s);
    vis[s] = 1;
    ++cnt;
    for(auto i : v[s]){
        if(!vis[i]){
            dfs(i);
        }
        else{
            cnt+=dp[i];
            dq.push_back(i);
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin>>n;
    v.resize(n+1);
    vis.resize(n+1, 0);
    dp.resize(n+1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin>>x;
        v[i].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            dfs(i);
            // cout<<endl;
            while(dq.size()){
                // cout<<dq.front()<<' '<<cnt<<' '<<dq.back()<<endl;
                if(dq.front()==dq.back()){
                    while(dq.size()){
                        dp[dq.front()] = cnt;
                        dq.pop_front();
                    }
                }
                else{
                    int s = dq.front();
                    dp[dq.front()] = cnt--;
                    dq.pop_front();
                }
            }
            cnt = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout<<dp[i]<<' ';
    cout<<'\n';
    return 0;
}