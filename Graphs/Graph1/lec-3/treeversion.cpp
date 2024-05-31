#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007


struct trio
{
    int zeros=0;
    int ones=0;
    int inv=0;
};

bool condition(trio &a,trio&b){
    return (a.ones*b.zeros<b.ones*a.zeros);
};

trio dfs(vector<vector<int>> &adj, vector<int> &w, int root, int par){
    trio curr;
    vector<trio> kids;
    for(auto it: adj[root]){
        if(it!=par){
            kids.push_back(dfs(adj,w,it,root));
        }
    }

    sort(kids.begin(),kids.end(),condition);

    if(w[root]==1){
        curr.ones++;
    }else{
        curr.zeros++;
    }

    for(trio it: kids){
        curr.inv+=it.inv;
        curr.inv+=curr.ones*it.zeros;
        curr.ones+=it.ones;
        curr.zeros+=it.zeros;
    }

    return curr;
}

void solve(){
    int n; cin>>n;
    vector<int>w(n+1);
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<dfs(adj,w,1,0).inv;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}
