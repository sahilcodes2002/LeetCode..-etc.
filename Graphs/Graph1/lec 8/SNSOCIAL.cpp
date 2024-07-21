#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>

vector<vi> hour;


vi r={-1, -1, 0, 1, 1, 1, 0, -1};
vi c={0, -1, -1, -1, 0, 1, 1, 1};

bfs(int n, int m, vector<pair<int,int>> &sources){
	vector<vi> vis(n,vi(m,0));
	int time = 0;
	queue<pair<int,int>> q;
	//q.push(make_pair(i,j));
	for(int i=0;i<sources.size();i++){
		q.push(sources[i]);
	}

	while(!q.empty()){
		int sz = q.size();
		while(sz--){
			pair<int,int> x = q.front();
			q.pop();
			vis[x.first][x.second]=1;
			if(hour[x.first][x.second] == -1){
				hour[x.first][x.second] = time;
			}else{
				hour[x.first][x.second] = min(hour[x.first][x.second],time);
			}
			
			
			for(int k=0;k<8;k++){
				int row = x.first+r[k];
				int col = x.second+c[k];
				if(row>=0 && col>=0 && row<n && col<m){
					if(vis[row][col]==0){
						q.push(make_pair(row,col));
					}
				}
			}
		}
		time++;
	}

}


void solve(){

	int n,m; cin>>n>>m;
	hour.clear();
	hour.assign(n,vi(m,-1));
	vector<vi>arr(n,vi(m));

	int mx = LLONG_MIN;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			mx = max(mx,arr[i][j]);
		}
	}

	vector<pair<int,int>> sources;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==mx){
				sources.push_back(make_pair(i,j));
			}
		}
	}
	bfs(n,m,sources);
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans = max(ans,hour[i][j]);
		}
	}

	cout<<ans<<endl;


}



int32_t main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


