#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>

class disjointSetUnion{
	vector<int>par;
	vector<int> sizes; //for union by rank (rank decided by size of the tree)
	int sz;
	int noOfcomponents;
public:
	disjointSetUnion(int n){
		par.assign(n+1,0);
		sizes.assign(n+1,1);
		noOfcomponents=n;
		sz=n;
	}

	int root(int a){
		if(par[a]==0){
			return a;
		}

		int x = root(par[a]);
		par[a]=x;//path compression
		return x;
	}

	bool find(int a, int b){
		a=root(a);
		b=root(b);
		return a==b;
	}

	void uni(int a, int b){
		a=root(a);
		b=root(b);
		if(a==b){
			return;
		}
		if(sizes[a]<sizes[b]){
			swap(a,b);
		}
		par[b] = a;
		sizes[a]+=sizes[b];
		noOfcomponents--;
	}
	int totalSetsdisjointSets(){
		return noOfcomponents;
	}
};


int32_t main(){
	disjointSetUnion a(5);
	cout<<a.find(1,2)<<endl;
	a.uni(1,2);
	cout<<a.find(1,2)<<endl;
	cout<<a.find(1,5)<<endl;
	a.uni(2,5);
	cout<<a.find(1,5)<<endl;
	cout<<a.totalSetsdisjointSets()<<endl;

	return 0;
}
