#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define mod 1000000007
#define vi vector<int>
#define mod 998244353
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


int powd(int x, int p) {
    int res = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        p /= 2;
    }
    return res;
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
            ans*= (powd(2,odd)+powd(2,even));
            ans%=mod;
        }
    }
    return ans;
}



int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		adj.clear();
	    adj.resize(n+1);
	    for(int i=0;i<m;i++){
	        int a,b;cin>>a>>b;
	        adj[a].push_back(b);
	        adj[b].push_back(a);
	    }
	    cout<<label123(n)<<endl;
	}
}
