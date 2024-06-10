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


struct querry
{
	int id;
	int gc;
	int f;
	int s;
	bool path;
	
};

bool cond1(querry &a, querry&b){
	return (a.gc>b.gc);
}

bool cond2(querry &a, querry&b){
	return (a.id<b.id);
}


int32_t main(){
	int n;
	cin>>n;
	int t;
	cin>>t;
	vector<querry> querries(t);
	for(int i=0;i<t;i++){
		querries[i].id=i;
		cin>>querries[i].f>>querries[i].s>>querries[i].gc;
	}

	sort(querries.begin(),querries.end(),cond1);
	for(auto &it: querries){
		//cout<<it.gc<<endl;
	}

	disjointSetUnion d(n);

	int lastQuerryGCD=n+1;
	for(auto &it: querries){
		for(int i=it.gc;i<=lastQuerryGCD-1;i++){
			for(int j=i;j+i<=n;j++){
				d.uni(j,j+i);
			}
		}
		it.path=d.find(it.f,it.s);
		lastQuerryGCD=it.gc;
	}
	sort(querries.begin(),querries.end(),cond2);
	for(auto &it: querries){
		cout<<it.path<<endl;
	}
	
	return 0;
}
