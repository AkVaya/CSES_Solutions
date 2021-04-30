#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int currAns = 0;
vector<int> answers;
int partition_size;
int a[nax];
int cnt[nax];
vector<pair<pair<int, int>,int> >queries;
bool mo_cmp(const pair<pair<int, int>,int> &x, const pair<pair<int, int>,int> &y){
    int left_x=x.first.first/partition_size;
    int left_y=y.first.first/partition_size;
    if(left_x!=left_y)
        return left_x<left_y;
    return x.first.second<y.first.second;
}
void add(int& x){
    if(!cnt[x])
        currAns++;
    ++cnt[x];
}
void remove(int& x){
    if(cnt[x]==1)
        currAns--;
    --cnt[x];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin>>n>>q;
    queries.resize(q);
    answers.resize(q);
    partition_size=sqrt(n);
    map<int, int> m;
    int x = 0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(!m.count(a[i]))
            m[a[i]]=x++;
        a[i] = m[a[i]];
    }
    for (int i = 0; i < q; ++i)
    {
        cin>>queries[i].first.first>>queries[i].first.second;
        queries[i].first.first--;
        queries[i].first.second--;
        queries[i].second = i;
    }
    sort(queries.begin(), queries.end(),mo_cmp);
    int mo_left=0,mo_right=-1;
    for (int i = 0; i < q; ++i)
    {
        int left=queries[i].first.first;
        int right=queries[i].first.second;
        while(mo_right<right){
            mo_right++;
            add(a[mo_right]);
        }
        while(mo_right>right){
            remove(a[mo_right]);
            mo_right--;
        }
        while(mo_left<left){
            remove(a[mo_left]);
            ++mo_left;
        }
        while(mo_left>left){
            --mo_left;
            add(a[mo_left]);
        }
        answers[queries[i].second] = currAns;
    }
    for (int i = 0; i < q; ++i)
    {
        cout<<answers[i]<<'\n';
    }
    return 0;
}