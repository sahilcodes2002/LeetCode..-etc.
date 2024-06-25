#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>


vector<vector<pair<int, char>>> adj;

vi distanceColor(int n, char col, int origin){
	vector<int> distance(n+1,-1);
	distance[origin] = 0;
	queue<int> q;
	q.push(origin);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(const auto& p : adj[x]){
			int node = p.first;
			if(distance[node]!=-1){
				continue;
			}
			char color = p.second;
			if(color == col){
				distance[node] = distance[x]+1;
				q.push(node);
			}
		}
	}

	return distance;
}


int32_t main() {
    int n, m; cin>>n>>m;
    adj.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        pair<int, char> x(b, c);
        pair<int, char> y(a, c);
        adj[a].push_back(x);
        adj[b].push_back(y);
    }

    int origin,destination;
    cin>>origin>>destination;
    vi ds = distanceColor(n,'r',origin);
    cout<<ds[2]<<endl;
    vi dd = distanceColor(n,'g',destination);

    int shortest_path = 10000007;
    for(int i=1;i<=n;i++){
    	if(i==origin || i== destination){
    		continue;
    	}
    	if(dd[i]==-1 || ds[i]==-1){
    		continue;
    	}
    	shortest_path = min(shortest_path, dd[i]+ds[i]);

    }

    cout<<shortest_path<<endl;

}
