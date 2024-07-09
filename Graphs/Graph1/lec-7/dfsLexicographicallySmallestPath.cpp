#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>

vector<vi> adj;
vi vis;
vector<stack<int>> paths; 
stack<int> ans;

// void dfs(int i, stack<int> &st){
// 	vis[i]=1;
// 	st.push(i);
// 	paths[i]=st;
// 	for(auto it: adj[i]){
// 		if(vis[it]==1){
// 			continue;
// 		}
// 		dfs(it,st);
// 	}

// 	st.pop();
// }

void dfsLexicographicallySmallestPath(int i, stack<int> &st, int destination){
	vis[i]=1;
	st.push(i);
	paths[i]=st;
	if(i==destination){
		ans=st;
	}
	vi neigh;
	for(auto it: adj[i]){
		if(vis[it]==1){
			continue;
		}
		dfsLexicographicallySmallestPath(it,st,destination);
	}
	st.pop();
}



void solve(){
	int n,m; cin>>n>>m;
	adj.clear();
	adj.resize(n+1);
	vis.assign(n+1,0);
	paths.clear();
	paths.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i=1;i<=n;i++){
		sort(adj[i].begin(),adj[i].end());
	}

	stack<int> st;
	dfsLexicographicallySmallestPath(1,st,5);

	// for(int i=1;i<=n;i++){
	// 	stack<int> demo = paths[i];
	// 	vector<int> temp;
	// 	while(!demo.empty()){
	// 		int x = demo.top();
	// 		temp.push_back(x);
	// 		demo.pop();
	// 	}
	// 	reverse(temp.begin(),temp.end());
	// 	for(auto it: temp){
	// 		cout<<it<<" ";
	// 	}
	// 	cout<<endl;
	// }

	stack<int> demo = ans;
	vector<int> temp;
	while(!demo.empty()){
		int x = demo.top();
		temp.push_back(x);
		demo.pop();
	}
	reverse(temp.begin(),temp.end());
	for(auto it: temp){
		cout<<it<<" ";
	}

	
}


int32_t main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
