#include <bits/stdc++.h>
using namespace std;
 
int DFS_minimumTimetoburnTree(vector<vector<int>>&adj, int root,int parent, int n){
    //every node burns one of its child in an unit time.
    vector<int> childBurn;
    for(auto it: adj[root]){
        if(it!=parent){
            int x = DFS_minimumTimetoburnTree(adj,it,root,n);
            childBurn.push_back(x);
        }
    }
    sort(childBurn.rbegin(),childBurn.rend());
    int time=0;
    int d=1;
    for(auto it : childBurn){
        time=max(it+d,time);
        d++;
    }
    return time;

}

vector<int> level(100001);
void DfsPrintWithLevel(vector<vector<int>>&adj,int par,int root){
    level[root]=level[par]+1;
    cout<<level[root]<<" "<<root<<endl;

    for(auto it : adj[root]){
        if(it!=par){
            DfsPrintWithLevel(adj,root,it);
        }
    }
}




vector<int> subtree(10001,0);
void DfsNodeinsubtree(vector<vector<int>>&adj,int par,int root){
    int subtreesize=1;
    for(auto it : adj[root]){
        if(it!=par){
            DfsNodeinsubtree(adj,root,it);
            subtreesize+=subtree[it];
        }
    }
    subtree[root]=subtreesize;
    cout<<root<<" "<<subtreesize<<endl;
}



vector<int> ancestorSum(10001,0);
vector<int> NodeValue= {0,11, 12, 13, 14, 15};
void dfsAncestorSum(vector<vector<int>>&adj,int par, int root){
    ancestorSum[root]=ancestorSum[par]+NodeValue[root];
    cout<<root<<" "<<ancestorSum[root]<<endl;
    for(auto it: adj[root]){
        if(it!=par){
            dfsAncestorSum(adj,root,it);
        }
    }
}

int n=10;
vector<vector<int>>dp(n+1,vector<int>(2,0));
void DfsminimumVertexCover(vector<vector<int>>&adj,int par,int root){
    dp[root][0]=1;
    for(auto it: adj[root]){
        if(it!=par){
            DfsminimumVertexCover(adj,root,it);
            dp[root][0]+=dp[it][1];
            dp[root][1]+=dp[it][0];
        }
    }
}

int32_t main() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    DfsminimumVertexCover(adj,0,1);
    cout<<min(dp[1][0],dp[1][1]);
    return 0;
}
