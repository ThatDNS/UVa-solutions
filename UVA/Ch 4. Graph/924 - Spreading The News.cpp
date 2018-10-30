// Problem: 924 - Spreading The News
/*Concept
Run DFS. Along with it calculate distance of each node from the source node.
Then count the number of occurances of each distance. Ignore the distance 0 (source node) as it'll always be 1.
After counting, return the first maximum number that you find in it. The number is M and it's index is D.
*/
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

void BFS(int u);
vector<vi> adjList;
vb visited;
vector<int> dist;
int M=0, D=1;

int main(){
	short int n, t;
	cin >> n;
	int u, v, size, test;
	adjList.assign(n+1, vector<int>());
	visited.assign(n+1, false);
	dist.assign(n, 0);
	for(int i=0; i<n; i++){
		cin >> size;
		for(int j=0; j<size; j++){
			cin >> v;
			adjList[i].pb(v);
		}
	}
	cin >> t;
	while(t--){
		M=-1;
		visited.assign(n+1, false);
		dist.assign(n, 0);
		cin >> test;
		if(adjList[test].size()==0)
			cout << "0" << endl;
		else{
			BFS(test);
			sort(dist.begin(), dist.end());
			int count[dist[n-1]+2];
			memset(count, 0, sizeof(count));
			for(int i=0; i<n; i++){
				count[dist[i]]++;
			}
			for(int i=1; i<=dist[n-1]; i++){
				if(count[i] > M){
					M = count[i];
					D = i;
				}
			}
			cout << M << " " << D << endl;
		}
	}
	return 0;
}

void BFS(int u){
	queue<int> q;
	visited[u] = true;
	q.push(u);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i: adjList[v]){
			if(!visited[i]){
				dist[i] = dist[v]+1;
				visited[i] = true;
				q.push(i);
			}
		}
	}
}
