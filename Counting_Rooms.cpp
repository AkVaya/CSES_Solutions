#include<bits/stdc++.h>
using namespace std;
const int nax = 1e3+69;
bool vis[nax][nax];
char a[nax][nax];
int n,m,ans = 0;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
bool check(int x,int y){
	return (x<n && x>=0 && y<m && y>=0);
}
void dfs(int i,int j){
	vis[i][j] = true;
	for (int z = 0; z < 4; ++z)
	{
		if(check(i+dx[z],j+dy[z]) && !vis[i+dx[z]][j+dy[z]])
			dfs(i+dx[z],j+dy[z]);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);	
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
			vis[i][j] = (a[i][j]=='#');
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!vis[i][j]){
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<ans<<'\n';


	return 0;
}