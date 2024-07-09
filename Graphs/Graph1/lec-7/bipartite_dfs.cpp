#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>

vector<vi>adj;
vector<int> col;
bool dfs(int i ){
	bool bip = true;
	for(auto it: adj[i]){
		if(col[it]!=-1){
			if(col[it]==col[i]){
				return 0;
			}
			continue;
		}
		col[it] = 1 - col[i];
		bip &= dfs(it);
	}
	return bip;
}



void solve(){
	int n,m;
	cin>>n>>m;
	adj.clear();
	adj.resize(n+1);
	col.clear();
	col.assign(n+1,-1);

	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	

	bool isbipartite = true;

	for(int i=1;i<=n;i++){
		if(col[i]==-1){
			col[i]=1;
			isbipartite&=dfs(i);
		}
	}
	cout<<isbipartite<<endl;

}



int32_t main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


