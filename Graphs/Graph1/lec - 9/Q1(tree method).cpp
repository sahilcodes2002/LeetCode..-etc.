#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>



vector<vi> edges;

void solve(){
	edges.clear();
	int n; cin>>n;

	for(int i=1;i<n;i++){
		int a,b; cin>>a>>b;
		edges.push_back({a,b});
	}

	int ans = n*((n*(n+1))/2); 

	for(auto it : edges){
		int x = ((min(it[1],it[0]))*(n-(max(it[0],it[1]))+1));
		ans -= x;
	}

	cout<<ans<<endl;
}




int32_t main(){

	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
