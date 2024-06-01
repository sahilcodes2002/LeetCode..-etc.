#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

vector<int> distSubtree;
vector<int> subTreesize;

void dfs1(vector<vector<int>> &adj , int par,int root){
    subTreesize[root]=1;
    for(auto it:adj[root]){
        if(it!=par){
            dfs1(adj,root,it);
            subTreesize[root]+=subTreesize[it];
            distSubtree[root]+=distSubtree[it]+subTreesize[it];
        }
    }
}

vector<int> distfromall;

void dfs2(vector<vector<int>> &adj , int par,int root, int n){
    for(auto it: adj[root]){
        if(it!=par){
            distfromall[it]=distfromall[root] - subTreesize[it] + (n - subTreesize[it]);
            dfs2(adj,root,it,n);
        }
    }
}

void solve(){
    int n; cin>>n;
    distSubtree.assign(n+1,0);
    subTreesize.assign(n+1,0);
    distfromall.assign(n+1,0);

    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(adj,0,1);
    distfromall[1]=distSubtree[1];
    dfs2(adj,0,1,n);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<distfromall[i]<<endl;
    }
    return;
}

int32_t main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
