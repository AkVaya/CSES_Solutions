#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, q;
	cin>>n>>q;
	char c[n+1][n+1];
	vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j){
			cin>>c[i][j];
			if(c[i][j]=='*')
				dp[i][j]++;
		}
	/*for (int i = 1; i <= n; ++i)
	{
		dp[i][0] +=dp[i-1][0];
		dp[0][i] +=dp[0][i-1];
	}*/
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
		}
	}
	/*cout<<endl<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<dp[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	while(q--){
		int x1, x2, y1, y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]<<endl;
	}
	return 0;
}