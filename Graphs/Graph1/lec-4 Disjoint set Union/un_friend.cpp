#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>

class disjointSetUnion{
	vector<int>par;
	int sz;
	int connectedComponents;
	vector<int> sizes;
public:
	disjointSetUnion(int n){
		par.assign(n+1,0);
		sizes.assign(n+1,1);
		sz=n;
		connectedComponents=n;
	}

	int root(int a){
		if(par[a]==0){
			return a;
		}

		int p = root(par[a]);
		par[a]=p;
		return p;
	}

	bool find(int a,int b){
		a = root(a);
		b = root(b);
		return a==b;
	}
	int uni(int a, int b){
		a=root(a);
		b=root(b);
		if(a==b){
			return 0;
		}
		if(sizes[a]<sizes[b]){
			swap(a,b);
		}
		sizes[a]+=sizes[b];
		par[b]=a;
		connectedComponents--;
		return 1;
	}
	int DistinctComponents(){
		return connectedComponents;
	}
};

int32_t main(){
	int n;
	cin>>n;

	int q = (n*(n-1))/2;

	vector<pair<int,int>> unfrnd(q);
	for(pair<int,int>&x : unfrnd){
		cin>>x.first>>x.second;
	}

	vi ans;
	disjointSetUnion d(n);
	for(auto it: unfrnd){
		d.uni(it.first,it.second);
		ans.push_back(d.DistinctComponents());
	}
	reverse(ans.begin(),ans.end());
	for(auto it: ans){
		cout<<it<<endl;
	}
	return 0;

}
