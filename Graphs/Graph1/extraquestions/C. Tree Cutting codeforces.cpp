https://codeforces.com/contest/1946/problem/C


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>


vi arr;
vector<vi> adj;


int dfs(int i, int &count, int mid){
	int sz=1;
	arr[i]=1;
	for(auto it: adj[i]){
		if(arr[it]==1){
			continue;
		}
		int x = dfs(it,count,mid);
		sz+=x;
	}
	if(sz>=mid){
		count++;
		sz=0;
	}

	return sz;
}




void solve(){
	int n,m;
	cin>>n>>m;
	
	arr.clear();
	adj.clear();
	arr.assign(n+1,0);
	adj.resize(n+1);

	for(int i=1;i<n;i++){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}




	int l=1;
	int h=n/(m+1);

	int ans = -1;
	while(l<=h){
		int mid = l+(h-l)/2;

		int count=0;
		arr.assign(n+1,0);
		int segs = dfs(1,count, mid);

		if(count>=(m+1)){
			ans = mid;
			l=mid+1;
		}else{
			h=mid-1;
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
