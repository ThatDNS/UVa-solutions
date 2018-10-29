// Problem: 11747 - Heavy Cycle Edges
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define EPS 1e-9
#define pb push_back

class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) { numSets--; 
		int x = findSet(i), y = findSet(j);
		if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
		else{ p[x] = y; setSize[y] += setSize[x];
		if (rank[x] == rank[y]) rank[y]++; } } }
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
	int n, m, u, v;
	long long w;
	vector<long long> store;
	vector<pair<long long, ii> > EdgeList;
	while(cin >> n >> m && (n!=0 || m!=0)){
		EdgeList.clear(); store.clear();
		for(int i=0; i<m; i++){
			cin >> u >> v >> w;
			EdgeList.pb(make_pair(w, ii(u, v)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(n);
		long long cost=0;
		for(int i=0; i<m; i++){
			pair<long long, ii> front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second))
				UF.unionSet(front.second.first, front.second.second);
			else
				store.pb(front.first);
		}
		if(store.size()==0){
			cout << "forest\n";
		}else{
			for(int j=0; j<(int)store.size(); j++){
				if(j==(int)store.size()-1)
					cout << store[j] << endl;
				else
					cout << store[j] << " ";
			}
		}
	}
	return 0;
}
