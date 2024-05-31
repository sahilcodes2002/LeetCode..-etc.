#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007


int dfs(vector<vector<int>> &adj, vector<int> &touched, int par, int root){
  touched[root]=1;
  int sz=1;
  for(auto it: adj[root]){
    if (!touched[it]) {  // Only visit if not already touched
            sz += dfs(adj, touched, root, it);
        }
  }
  return sz;
}

int powerWithMod(int a,int n=mod-2){
    if(!n){
        return 1;
    }
    int pd = powerWithMod(a,n/2);
    pd*=pd;pd%=mod;
    if(n&1){
        pd*=a;pd%=mod;
    }
    return pd;

}

int32_t main(){
  int n,k;
  cin>>n>>k;
  vector<vector<int>> adj(n+1);

  for (int i = 1; i < n; i++) {
        int a, b, col;
        cin >> a >> b >> col;
        if (col == 0) {
             adj[a].push_back(b);
             adj[b].push_back(a);
        }
    }

 vector<int> touched(n+1,0);
 int size = powerWithMod(n,k);
 for(int i=1;i<=n;i++){
   if(touched[i]==0){
    int s=dfs(adj,touched,0,i);
     size-=powerWithMod(s,k);
     //this is modular arithmatic 
     size = (size+mod)%mod;
     
   }
 }
 cout<<size<<endl;
 return 0;

}
