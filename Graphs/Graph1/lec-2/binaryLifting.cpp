#include <bits/stdc++.h>
using namespace std;
 
int dp[10001][20];
vector<int> in,out;
int t=0;
void dfs(vector<vector<int>>&adj, int par,int root){
    dp[root][0]=par;
    in[root]=(++t);

    for(int i=1;i<20;i++){
        int j_minius_1 = dp[root][i-1];
        dp[root][i]=dp[j_minius_1][i-1];
    }

    for(auto it : adj[root]){
        if(it!=par){
            dfs(adj,root,it);
        }
    }
    out[root]=(++t);
}

bool is_first_ancestor_of_sec(int u, int v){
    return ((in[u]<=in[v])&&(out[u]>=out[v]));
}


int lca(int node1, int node2){
    if(is_first_ancestor_of_sec(node1,node2)){
        return node1;
    }
    if(is_first_ancestor_of_sec(node2,node1)){
        return node2;
    }

    for(int i=19;i>=0;--i){
        if(!is_first_ancestor_of_sec(dp[node1][i],node2)){
            node1=dp[node1][i];
        }
    }
    return dp[node1][0];
}




int32_t main() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    in.resize(n+1);
    out.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    

    dfs(adj,1,1);
    int node1,node2;
    cin>>node1>>node2;
    
    cout<<lca(node1,node2);
    return 0;
}
