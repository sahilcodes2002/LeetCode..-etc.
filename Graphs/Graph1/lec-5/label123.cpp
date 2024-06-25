#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>

vector<vi> adj;
bool isPossible(int n, int origin, vi &col,int &odd, int &even){
    
    queue<int> q;
    col[origin]=0;
    even++;
    q.push(origin);

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
            q.push(it);
            col[it] = 1-col[x];
            if(col[it]==0){
                even++;
            }else{
                odd++;
            }

        }
    }
    return true;
}

int label123(int n){
    vi col(n+1,-1);
    int odd=0;
    int even=0;
    int ans = 1;
	for(int i=1;i<=n;i++){
        odd=0;
        even=0;
        if(col[i]==-1){
            if(!isPossible(n,i,col,odd,even)){
                return 0;
            }
            ans*= (pow(2,odd)+pow(2,even));
        }
    }
    return ans;
}



int32_t main(){
	int n,m; cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<label123(n)<<endl;
}
