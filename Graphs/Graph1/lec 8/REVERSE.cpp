#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>
#define inf LLONG_MAX



vector<vector<pair<int,int>>> adj;



int bfs01(int n){
	vi distances(n+1,inf);
	deque<int> q;
	q.push_back(1);
	distances[1]=0;

	while(!q.empty()){
		int x = q.front();
		q.pop_front();
		
		for(pair<int,int> it : adj[x]){
			int node = it.first;
			int w = it.second;

			if(distances[x] + w < distances[node]){
				distances[node] = distances[x]+w;
				if(w==0){
					q.push_front(node);
				}else{
					q.push_back(node);
				}
			}
		}
	}

	return distances[n]!=inf? distances[n] : -1;
}



void solve(){
	int n,m; cin>>n>>m;
	adj.clear();
	adj.resize(n+1);

	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;
		adj[a].push_back(make_pair(b,0));
		adj[b].push_back(make_pair(a,1));
	}

	cout<<bfs01(n)<<endl;

}


int32_t main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


