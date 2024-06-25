#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>


vector<vi> adj;

void gcd1(int n, int m, int origin){
    vi visited(n+1,0);
    queue<int> q;
    q.push(origin);
    visited[origin]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<endl;
        for(auto it: adj[x]){
            if(visited[it]){
                continue;
            }
            q.push(it);
            visited[it]=1;
        }
    }
}





vi gcd2(int n,int m, int origin){
    queue<int> q;
    q.push(origin);
    vi distance(n+1,-1);
    distance[origin] = 0;
    while(!q.empty()){
        int x = q.front();
        cout<<x<<": "<<distance[x]<<endl;
        q.pop();
        for(auto it: adj[x]){
            if(distance[it]!=-1){
                continue;
            }
            q.push(it);
            distance[it]=distance[x]+1;
        }
    }
    return distance;
}





vi shortest_path_gcd(int n, int m, int start, int destination){
    
    vi parent(n+1,0);
    vi distance(n+1,-1);
    distance[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x==destination){
            break;
        }
        for(auto it: adj[x]){
            if(distance[it]!=-1){
                continue;
            }
            parent[it] = x;
            distance[it]=distance[x]+1;
            q.push(it);
        }
    }

    if(distance[destination]==-1){ // if there is no path....
        cout<<"No Path"<<endl;
        return {};
    }

    vector<int>path;
    while(destination!=0){
        path.push_back(destination);
        destination=parent[destination];
    }
    reverse(path.begin(),path.end());
    for(auto it : path){
        cout<<it<<endl;
    }
    return path;
}
    


vi nodesInAtleastOnshortestPath(int n, int origin,int destination){
    vector<vi> parent(n+1);
    vi distance(n+1,-1);
    distance[origin]=0;
    queue<int> q;
    q.push(origin);

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int x = q.front();
            q.pop();
            for(auto it: adj[x]){
                if(distance[it]!=-1){
                    if(distance[x]+1==distance[it]){
                        parent[it].push_back(x);
                    }
                    continue;
                }
                q.push(it);
                parent[it].push_back(x);
                distance[it]=distance[x]+1;
            }
        }

        if(distance[destination]!=-1){
            break;
        }
    }

    if(distance[destination]==-1){
        cout<<"no path"<<endl;
        return {};
    }
    int node = destination;
    vi markparents(n+1,0);
    markparents[destination] = 1;
    queue<int> parentq;
    parentq.push(destination);
    vi ans;

    while(!parentq.empty()){
        int x = parentq.front();
        parentq.pop();
        ans.push_back(x);
        for(auto it: parent[x]){
            if(markparents[it]!=0){
                continue;
            }
            markparents[it] = 1;
            parentq.push(it);
        }
    }

    for(auto it: ans){
        cout<<it<<endl;
    }

    return ans;
}  








vi giveDistanceBfs(int n, int origin){
    vi distance(n+1,-1);
    distance[origin]=0;
    queue<int> q;
    q.push(origin);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto it: adj[x]){
            if(distance[it]!=-1){
                continue;
            }
            distance[it]=distance[x]+1;
            q.push(it);
        }
    }
    return distance;
}

vi nodesInAtleastOnshortestPath2(int n, int origin,int destination){
    vi distancefromO = giveDistanceBfs(n,origin);
    vi distancefromD = giveDistanceBfs(n,destination);

    if(distancefromO[destination]==-1){
        return {};
    }



    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(distancefromO[i]==-1 || distancefromD[i]==-1){
            continue;
        }
        if(distancefromO[i]+distancefromD[i]==distancefromO[destination]){
            ans.push_back(i);
            cout<<i<<endl;
        }
    }

    return ans;
}


int connectedComponents=0;
bool isPossible(int n){
    vi col(n+1,-1);
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            connectedComponents++;
            col[i]=0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(auto it: adj[x]){
                    if(col[it]!=-1){
                        if(col[it]==col[x]){
                            return false;
                        }
                        continue;
                    }
                    col[it] = 1-col[x];
                    q.push(it);
                }
            }
        }
    }

    return true;
}

//bipartitioning of graph
int totalPossibleValidBipartitionings(int n){
    if(!isPossible(n)){
        return 0;
    }

    return pow(2,connectedComponents);

}






int32_t main(){
    int n,m; cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //shortest_path_gcd(n,m,4,5);
    //nodesInAtleastOnshortestPath(n,3,6);
    //nodesInAtleastOnshortestPath2(n,3,6);
    cout<<totalPossibleValidBipartitionings(n);
    return 0;
}
