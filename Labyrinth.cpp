#include<bits/stdc++.h>
using namespace std;
const int nax = 1e3+69;
int vis[nax][nax];
char a[nax][nax];
int n,m;
string res = "";
int mn = INT_MAX;
void bfs(int x,int y){
    queue<pair<pair<int, int>, int> > q;
    q.push({{x, y}, 0});
    vis[x][y] = 0;
    while(q.size()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        //cout<<i<<' '<<j<<endl;
        if(a[i][j]=='B'){
            while(dist){
                if(i>0 && vis[i-1][j]==dist-1){
                    res+="D";
                    dist--;
                    i--;
                }
                else if(i<n-1 && vis[i+1][j]==dist-1){
                    res+="U";
                    dist--;
                    i++;
                }
                else if(j>0 && vis[i][j-1]==dist-1){
                    res+="R";
                    dist--;
                    j--;
                }
                else if(j<m-1 && vis[i][j+1]==dist-1){
                    res+="L";
                    dist--;
                    j++;
                }
            }
            //cout<<dist<<endl;
            reverse(res.begin(), res.end());
            break;
        }
        if(i+1<n && vis[i+1][j]==INT_MAX){
            vis[i+1][j] = dist+1;
            q.push({{i+1,j},dist + 1});
        }
        if(i-1>=0 && vis[i-1][j]==INT_MAX){
            vis[i-1][j] = dist+1;
            q.push({{i-1,j},dist+1});
        }
        if(j+1<m && vis[i][j+1]==INT_MAX){
            vis[i][j+1] = dist+1;
            q.push({{i,j+1},dist+1});
        }
        if(j-1>=0 && vis[i][j-1]==INT_MAX){
            vis[i][j-1] = dist+1;
            q.push({{i,j-1},dist+1});
        }

    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);   
    cin>>n>>m;
    pair<int,int> start;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>a[i][j];
            vis[i][j] = (a[i][j]=='#' ? -1 : INT_MAX);
            if(a[i][j]=='A')
                start = {i,j};
 
        }
    }
    bfs(start.first,start.second);
    //cout<<res<<endl;
    if(!res.length())
        cout<<"NO\n";
    else{
        cout<<"YES\n"<<res.length()<<'\n'<<res<<'\n';
    }
    return 0;
}