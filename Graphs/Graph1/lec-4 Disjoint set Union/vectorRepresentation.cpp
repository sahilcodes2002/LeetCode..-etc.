#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>

class disjointSetUnion{
	vector<vi> sets;
	vi loc;
	int sz;
	public:
	disjointSetUnion(int n){
		sets.resize(n+1);
		loc.resize(n+1);
		sz=n;
		for(int i=1;i<=n;i++){
			sets[i].push_back(i);
			loc[i]=i;
		}
	}

	bool find(int a , int b){
		if(a>sz || b>sz){
			return 0;
		}

		return loc[a]==loc[b];
	}

	void uni(int a, int b){
		if(a>sz || b>sz){
			return ;
		}

		if(find(a,b)){
			return;
		}

		if(sets[loc[a]]>sets[loc[b]]){
			swap(a,b);
		}

		int la = loc[a];
		int lb = loc[b];
		while(sets[la].size()>0){
			int a = sets[la].back();
			sets[la].pop_back();
			loc[a]=lb;
			sets[lb].push_back(a);
		}
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
}
