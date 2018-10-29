// Problem: 10600 - ACM Contest and Blackout
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
void BFS(int u, int disabled);
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
vector<pair<int, ii> > EdgeList;
vector<vector<int> > adjList;
vb visited;
int main(){
	short int t, n, c;
	int m, u, v, count=0, cc=0;
	vi chosen;
	cin >> t;
	while(t--){
		EdgeList.clear(); chosen.clear();
		adjList.clear(); visited.clear();
		cin >> n >> m;
		adjList.assign(n+2, vi()); cc=0;
		for(int i=0; i<m; i++){
			cin >> u >> v >> c;
			EdgeList.pb(make_pair(c, ii(u, v)));
			adjList[u].pb(v);
			adjList[v].pb(u);
		}
		sort(EdgeList.begin(), EdgeList.end());
		int firCost=0, secCost=INT_MAX, tempCost=0;
		UnionFind UF(n+1);
		visited.assign(n+2, false); count=0;
		for(int k=1; k<=n; k++){
			if(!visited[k]){
				BFS(k, -1);
				cc++;
			}
		}
		for(int i=0; i<m; i++){
			pair<int, ii> front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				firCost += front.first;
				chosen.pb(i);
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		for(int i: chosen){
			UnionFind UF1(n+1); tempCost=0;
			visited.assign(n+2, false); count=0;
			for(int k=1; k<=n; k++){
				if(!visited[k]){
					BFS(k, i);
					count++;
				}
			}
			if(count == cc){
				for(int j=0; j<m; j++){
					if(j==i)
						continue;
					pair<int, ii> front = EdgeList[j];
					if(!UF1.isSameSet(front.second.first, front.second.second)){
						tempCost += front.first;
						UF1.unionSet(front.second.first, front.second.second);
					}
				}
				if(tempCost >= firCost)
					secCost = min(secCost, tempCost);
			}
		}
		cout << firCost << " " << secCost << endl;
	}
	return 0;
}

void BFS(int u, int disabled){
	pair<int, ii> getDis = EdgeList[disabled];
	int a = getDis.second.first, b = getDis.second.second;
	queue<int> q;
	visited[u] = true;
	q.push(u);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int j: adjList[v]){
			if(v==a && j==b)
				continue;
			if(!visited[j]){
				visited[j] = true;
				q.push(j);
			}
		}
	}
}
