#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
vector<int> parent, sz;
int find(int s){
    // cout<<s<<endl;
    if(parent[s]==s)
        return s;
    return parent[s] = find(parent[s]);
}
void merge(int a, int b){
    int pa = find(a), pb = find(b);
    if(sz[pb] > sz[pa])
        swap(pa, pb);
    sz[pa] += sz[pb];
    sz[pb] = 0;
    parent[pb] = pa;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, m, y, z;
    cin>>n>>m;
    parent.resize(n+1);
    sz.resize(n+1);
    for (int i = 1; i <= n; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
    int comp = n, mx = 1;
    // cout<<"YAHA"<<endl;
    for (int i = 1; i <= m; ++i)
    {
        cin>>x>>y;
        int px = find(x), py = find(y);
        // cout<<px<<' '<<py<<endl;;
        if(px != py){
            merge(px, py);
            comp--;
        }
        mx = max(mx, max(sz[px], sz[py]));
        cout<<comp<<' '<<mx<<'\n';
    }
    return 0;
}