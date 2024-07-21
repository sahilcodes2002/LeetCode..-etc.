#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>
#define inf 1000000007

vector<int> r = {-1,0,1,0};
vector<int> c = {0, 1,0,-1};

vector<vector<pair<int,int>>> adj;


int bfs01(int n,int m){
	deque<pair<int,int>> q;
	vector<int> weight(n*m,inf);
	weight[0]=0;
	q.push_back({0,0});

	while(!q.empty()){
		auto x = q.front();
		int par = x.first;
		q.pop_front();
		
		for(auto it: adj[par]){
			int node = it.first;
			int w = it.second;
			if(weight[par] + w < weight[node]){
				weight[node] = weight[par] + w;
				if(w==0){
					q.push_front(it);
				}else{
					q.push_back(it);
				}
			}
		}
	}
	return weight[(n*m)-1];
}

void solve(){
	int n,m; cin>>n>>m;
	adj.clear();
	adj.resize(n*m);
	vector<vector<char>> matrix(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matrix[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<4;k++){
				int row = i+r[k];
				int col = j+c[k];

				if(row<n && col<m && row >=0 && col>=0){
					if(matrix[i][j]=='u' && k==0){
						adj[(i*m)+j].push_back({(row*m)+col,0});
						continue;
					}
					else if(matrix[i][j]=='d' && k==2){
						adj[(i*m)+j].push_back({(row*m)+col,0});
						continue;
					}
					else if(matrix[i][j]=='l' && k==3){
						adj[(i*m)+j].push_back({(row*m)+col,0});
						continue;
					}
					else if(matrix[i][j]=='r' && k==1){
						adj[(i*m)+j].push_back({(row*m)+col,0});
						continue;
					}
					adj[(i*m)+j].push_back({(row*m)+col,1});
				}
				
			}
		}
	}


	int changes = bfs01(n,m);

	cout<<changes<<endl;



}

int32_t main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
