#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
const ll nax = 569;
bool adj[nax][nax];
ll dist[nax][nax];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y, z, q;
    cin>>n>>m>>q;
    for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j){
                if(i==j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = LLONG_MAX;
            }
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>z;
        adj[x][y] = adj[y][x] = 1;
        dist[x][y] = dist[y][x] = min(dist[x][y], z);
         // min(dist[y][x], z);
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<(dist[x][y]==LLONG_MAX ? -1 : dist[x][y])<<'\n';
    }
    

    return 0;
}