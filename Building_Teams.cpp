#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e5 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x, y;
    cin>>n>>m;
    vector<vector<int> >v(n+1);
    vector<int> clr(n+1, -1);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool check = true;
    for (int i = 1; i <= n; ++i)
    {
        if(clr[i]==-1){
            clr[i] = 1;
            queue<int> q;
            q.push(i);
            while(q.size()){
                int curr = q.front();
                q.pop();
                for(auto i : v[curr]){
                    if(clr[i]==-1){
                        clr[i] = 3 - clr[curr];
                        q.push(i);
                    }
                    else if(clr[i]==clr[curr]){
                        check = false;
                        break;
                    }
                }
                if(!check)
                    break;
            }
            if(!check)
                break;
        }
    }
    if(!check)
        cout<<"IMPOSSIBLE\n";
    else{
        for (int i = 1; i <= n; ++i)
            cout<<clr[i]<<' ';
        cout<<'\n';
    }
    return 0;
}