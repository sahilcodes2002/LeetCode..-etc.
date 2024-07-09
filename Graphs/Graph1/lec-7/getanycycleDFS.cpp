#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>

vector<vi>adj;
vector<int> par;
int cycst,cycend;
vi cycle;



void getanycycle(){
	while(cycst!=cycend){
		cycle.push_back(cycst);
		cycst=par[cycst];
	}
	cycle.push_back(cycend);
}



bool dfs(int i){

	bool cycle = false;
	for(auto it: adj[i]){

		if(it==par[i]){
			continue;
		}
		if(par[it]!=-1){
			cycst=i;
			cycend=it;
			getanycycle();
			return true;
		}
		par[it]=i;
		cycle |= dfs(it);
		if(cycle){
			return true;
		}
	}
	return cycle;
}


void solve(){
	int n,m;
	cin>>n>>m;
	adj.clear();
	adj.resize(n+1);
	par.clear();
	par.assign(n+1,-1);

	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	

	bool iscyclic = false;

	for(int i=1;i<=n;i++){
		if(par[i]==-1){
			par[i]=0;
			iscyclic|=dfs(i);
			if(iscyclic){
				break;
			}
		}
	}

	for(auto it : cycle){
		cout<<it<<" ";
	}
	cout<<endl;
}



int32_t main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


