#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>



vector<vi> edges;

class dsu{

	vi parent;
	vi sizes;
	int cc;
	public:
		dsu(int n){
			parent.assign(n+1,0);
			sizes.assign(n+1,1);
			cc = n;
		}

		int root(int a){
			if(parent[a]==0){
				return a;
			}

			int x = root(parent[a]);
			parent[a] = x;
			return x;
		}

		bool find(int a, int b){
			int rootofA = root(a);
			int rootofB = root(b);
			return rootofA == rootofB;
		}

		int uni(int a, int b){
			int rootofA = root(a);
			int rootofB = root(b);
			if(rootofA == rootofB){
				return 0;
			}

			if(sizes[rootofA] < sizes[rootofB]){
				swap(rootofA, rootofB);
			}

			parent[rootofB] = rootofA;
			sizes[rootofA] += sizes[rootofB];
			cc--;
		}

		int noOfCc(){
			return cc;
		}

};



bool comparator(vi a, vi b){
	if(a[0]>a[1]){
		swap(a[0],a[1]);
	}
	if(b[0]>b[1]){
		swap(a[0],a[1]);
	}

	if(a[0]<b[0]){
		return true;
	}
	else if(a[0]==b[0]){
		return a[1]<b[1];
	}
	return false;
}

void solve(){
	int n; cin>>n;

	edges.clear();

	for(int i=0;i<n-1;i++){
		int a,b; cin>>a>>b;
		edges.push_back({a,b});
	}

	sort(edges.begin(),edges.end(), comparator);

	int ans=0;
	for(int i=1;i<=n;i++){
		vector<vi> demo;

		for(auto it: edges){
			if(it[0]>=i && it[1]>=i){
				demo.push_back(it);
			}
		}
		
		for(int j=i;j<=n;j++){
			dsu set(n);
			for(auto it: demo){
				if(max(it[0],it[1])<=j){
					set.uni(it[0],it[1]);
				}
			}
			ans+=set.noOfCc();
		}
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
