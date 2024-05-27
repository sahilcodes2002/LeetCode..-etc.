#include <bits/stdc++.h>
using namespace std;
#define int long long



void calcLevels(vector<vector<int>>adj, int root, vector<int> &parent, vector<int> &level){
    level[root]=level[parent[root]]+1;
    for(auto it: adj[root]){
        if(it!=parent[root]){
            parent[it]=root;
            calcLevels(adj,it,parent,level);
        }
    }
}


int disstance(vector<vector<int>>adj,int root, int n,int node1, int node2){
    vector<int> level(n+1,0);
    vector<int>parent(n+1,0);
    calcLevels(adj,root,parent,level);
    int l1=level[node1];
    int l2=level[node2];
    if(level[node1]<level[node2]){
        swap(node1,node2);
    }
    while(level[node1]!=level[node2]){
        node1=parent[node1];
    }
    while(node1!=node2){
        node1=parent[node1];
        node2=parent[node2];
    }

    int x = (l1 - level[node1])+(l2 - level[node2]);
    return x;
}





int32_t main(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int node1, node2;
    cin>>node1>>node2;
    cout<<disstance(adj,1,n,node1,node2);

    return 0;

}
