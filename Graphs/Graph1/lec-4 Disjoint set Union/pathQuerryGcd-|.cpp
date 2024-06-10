#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>

class disjointSetUnion{
	vector<int> par;
	vector<int> sizes;
	int sz;
	int totalComponents;
public:
	disjointSetUnion(int n){
		par.assign(n+1,0);
		sizes.assign(n+1,1);
		sz=n;
		totalComponents = n;
	}

	int root(int a){
		if(par[a]==0){
			return a;
		}
		int p = root(par[a]);
		par[a]=p;  //path compression
		return p;
	}

	bool find(int a, int b){
		a = root(a);
		b = root(b);
		return a==b;
	}

	void uni(int a, int b){
		a = root(a);
		b = root(b);
		if(a==b){
			return;
		}
		if(sizes[a]<sizes[b]){
			swap(a,b); //union by rank
		}
		par[b]=a;
		sizes[a]+=sizes[b];
		totalComponents--;
	}

	int connectedComponents(){
		return totalComponents;
	}
};


int32_t main(){
	int n,G;
	cin>>n>>G;
	int t;
	cin>>t;
	vector<pair<int,int>> querry(t);
	for(int i=0;i<t;i++){
		cin>>querry[i].first>>querry[i].second;
	}
	disjointSetUnion d(n);
	for(int i=G;i<=n;i++){
		for(int j=i;j+i<=n;j+=i){//nlogn
			d.uni(j,j+i);
		}
	}

	for(auto it: querry){
		cout<<d.find(it.first,it.second)<<endl;
	}
	
	
	return 0;
}
