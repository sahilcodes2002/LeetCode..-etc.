#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<long long>


class find_union{
	int sz;
	vector<vector<int>> st;
	vector<int> loc;
public:
	find_union(int n){
		sz=n;
		st.resize(n+1);
		loc.resize(n+1);
		for(int i=1;i<=n;i++){
			loc[i]=i;
		}
		for(int i=1;i<=n;i++){
			st[i].push_back(i);
		}
		int k=0;
		
	}

	bool find(int a,int b){
		if(loc[a]==loc[b]){
			return true;
		}
		return false;
	}

	int uni(int a, int b){
		if(find(a,b)){
			return 0;
		}
		if(st[loc[a]].size()>st[loc[b]].size()){
			swap(a,b);
		}
		int la = loc[a];
		int lb = loc[b];

		while(!st[la].empty()){
			int x = st[la].back();
			st[la].pop_back();
			st[lb].push_back(x);
			loc[x]=lb;
		}
		sz--;
		return 1;
	}

	int sets(){
		return sz;
	}

};

int32_t main() {
    int n;
    cin>>n;
    vector<vi> st(26);
    for(int i=1;i<=n;i++){
    	string a;
    	cin>>a;

    	for(char it: a){
    		int x = it-'a';
    		st[x].push_back(i);
    	}
    }
    find_union dus(n);
    for(auto it: st){
    	for(int j=0;j+1<it.size();j++){
    		int u = it[j];
    		int v = it[j+1];
    		dus.uni(u,v);
    	}
    }
    cout<<dus.sets()<<endl;
	return 0;
}
