// Problem: 1112 - Mice and Maze
/*Concept:
Basically, you have to calculate how many mice escape from the given node.
Let's flip it around and calculate how many mice reach all different nodes if 
they all start from the given node. This will give you the answer.
Now, we're flipping it around so CHANGE THE DIRECTION OF EDGES as well.
Flip the directions of all edges.
*/
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define EPS 1e-9 // 10^-9
#define pb push_back
#define INF 1e9 // 10^9

int main(){
	short int N, E, u, v, w, flag=0;
	int tests, T, count=0, M;
	vector<vii> adjList;
	vi dist;
	cin >> tests;
	while(tests--){
		cin >> N; cin >> E; cin >> T; cin >> M;
		if(flag==1) cout << "\n";
		if(flag==0) flag=1;
		adjList.clear(); dist.clear(); count=0;
		adjList.assign(N+2, vii());
		dist.assign(N+2, INF);
		for(int i=1; i<=M; i++){
			cin >> u >> v >> w;
			adjList[v].pb(ii(u, w)); //the trick I told you above.
		}
		priority_queue<ii, vii, greater<ii> > pq;
		dist[E] = 0; pq.push(ii(0, E));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if(d > dist[u]) continue;
			for(int j=0; j<(int)adjList[u].size(); j++){
				ii v = adjList[u][j];
				if(dist[u]+v.second < dist[v.first]){
					dist[v.first] = dist[u]+v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		for(int i=1; i<=N; i++){
			if(dist[i] <= T)
				++count;
		}
		cout << count << endl;
	}
	return 0;
}

