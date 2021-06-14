#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e3 + 69;
bool vis[nax][nax];
int dist[nax][nax], n, m;
char a[nax][nax];
string res;
bool dfs(int i, int j){
    // cout<<i<<' '<<j<<endl;
    if(!i || !j || i==n-1 || j==m-1)
        return true;
    vis[i][j] = true;
    if(i+1<n && !vis[i+1][j] && dist[i+1][j]>res.length()+1){
        res+="D";
        if(dfs(i+1, j))
            return true;
        res.pop_back();
    }
    if(i && !vis[i-1][j] && dist[i-1][j]>res.length()+1){
        res+="U";
        if(dfs(i-1, j))
            return true;
        res.pop_back();
    }
    if(j+1<m && !vis[i][j+1] && dist[i][j+1]>res.length()+1){
        res+="R";
        if(dfs(i, j+1))
            return true;
        res.pop_back();
    }
    if(j && !vis[i][j-1] && dist[i][j-1]>res.length()+1){
        res+="L";
        if(dfs(i, j-1))
            return true;
        res.pop_back();
    }
    vis[i][j] = false;
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int stx, sty;
    queue<pair<int, int> > q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>a[i][j];
            dist[i][j] = INT_MAX;
            if(a[i][j]=='#')
                vis[i][j] = true;
            else if(a[i][j]=='M'){
                vis[i][j] = true;
                dist[i][j] = 0;
                q.push({i, j});
            }
            else if(a[i][j]=='A'){
                stx = i;
                sty = j;
            }
            else
                vis[i][j] = false;
        }
    }
    while(q.size()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        if(i+1<n && !vis[i+1][j]){
            vis[i+1][j] = true;
            dist[i+1][j] = 1 + dist[i][j];
            q.push({i+1, j});
        }
        if(i && !vis[i-1][j]){
            vis[i-1][j] = true;
            dist[i-1][j] = 1 + dist[i][j];
            q.push({i-1, j});
        }
        if(j+1<m && !vis[i][j+1]){
            vis[i][j+1] = true;
            dist[i][j+1] = 1 + dist[i][j];
            q.push({i, j+1});
        }
        if(j && !vis[i][j-1]){
            vis[i][j-1] = true;
            dist[i][j-1] = 1 + dist[i][j];
            q.push({i, j-1});
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            // cout<<dist[i][j]<<' ';
            if(a[i][j]=='#')
                vis[i][j] = true;
            else
                vis[i][j] = false;
        }
        // cout<<'\n';
    }
    bool check = dfs(stx, sty);
    if(!check)
        cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<res.length()<<'\n';
        cout<<res<<'\n';
    }
    return 0;
}