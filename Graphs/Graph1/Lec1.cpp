#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfsLevelWisePrint(vector<vector<int>>&adj, int n, int root){

    int parent[n+1];
    parent[root]=0;

    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int x = q.front();
            q.pop();
            cout<<x<<" ";
            for(int nb : adj[x]){
                if(nb != parent[x]){
                    q.push(nb);
                    parent[nb] = x;
                }
            }
        }
        cout<<endl;
    }

}


int LevelWithMaxSum(vector<vector<int>>&adj, int n, int root){
    int parent[n+1];
    parent[root]=0;

    queue<int> q;
    q.push(root);
    int ans = root;
    while(!q.empty()){
        int sz = q.size();
        int sum = 0;
        while(sz--){
            int curr = q.front();
            sum+=curr;
            q.pop();

            for(int nb : adj[curr]){
                if(nb!= parent[curr]){
                    q.push(nb);
                    parent[nb] = curr;
                }
            }
        }
        ans = max(ans, sum);
    }
    return ans;
}

int closestLeafToRoot(vector<vector<int>> &adj , int n ,int root){
    if(adj[root].size()==0){
        return root;
    }
    int parent[n+1];
    parent[root]=0;

    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(adj[x].size()==1){
            return x;
        }

        for(int nb : adj[x]){
            if(parent[x] != nb){
                q.push(nb);
                parent[nb] = x;
            }
        }
    
    }
}

vector<int> pathToClosestLeafFromRoot(vector<vector<int>> &adj , int n ,int root){
    int parent[n+1];
    parent[root]=0;

    queue<int> q;
    q.push(root);

    int leaf = -1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(adj[curr].size()==1){
            leaf = curr;
            break;
        }

        for(int nb : adj[curr]){
            if(nb != parent[curr]){
                q.push(nb);
                parent[nb]=curr;
            }
        }
    }

    vector<int> path;
    
    while(leaf!=0){
        path.push_back(leaf);
        leaf = parent[leaf];
    }
    return path;
}



int32_t main(){
    int n, root;
    cin>>n;
    cin>>root;
    vector<vector<int>> adj(n+1);    
    for(int i=0;i<n-1;i++){
        int x;
        int y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfsLevelWisePrint(adj, n, root);

    cout<<LevelWithMaxSum(adj, n ,root)<<endl;
    cout<<closestLeafToRoot(adj, n ,root)<<endl;

    vector<int> path = pathToClosestLeafFromRoot(adj, n, root);
    for(int it: path){
        cout<<it<<" ";
    }
    return 0;

}
