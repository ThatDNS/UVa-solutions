// Problem: 11631 - Dark roads
/* Concept:
Simply used Kruskal's algorithm. No big deal.
*/
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
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
	int V, E, u, v;
	long long w, total;
	vector<pair<int, ii> > EdgeList;
	while(cin >> V >> E && (V!=0 && E!=0)){
		EdgeList.clear(); total=0;
		for(int i=0; i<E; i++){
			cin >> u >> v >> w;
			EdgeList.pb(make_pair(w, ii(u, v)));
			total+=w;
		}
		sort(EdgeList.begin(), EdgeList.end());
		long long mst_cost = 0;
		UnionFind UF(V);
		for(int i=0; i<E; i++){
			pair<int, ii> front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){ // u,v not same set
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		cout << total-mst_cost << endl; 
	}
	return 0;
}

