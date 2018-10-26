// Problem: 11902 - Dominator
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<vector <int> > adjList;
vector<bool> visited;
vector<bool> OriVisited;
bool isDominated[100][100];
set<int> original, temp;
void DFS(int n);
void DFSUtil(int u, int off);
int main(){
	short int t, n, pos, test=0;
	cin >> t;
	while(t--){
		adjList.clear(); visited.clear(); OriVisited.clear();
		cin >> n;
		string breaker = "+";
		for(int i=1; i<=n; i++){
			if(i==n)
				breaker += "-+";
			else
				breaker += "--";
		}
		visited.assign(n+2, false);
		OriVisited.assign(n+2, false);
		adjList.assign(n+2, vector<int>());
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> pos;
				isDominated[i][j]=false;
				if(pos==1)
					adjList[i].pb(j);
			}
		}
		DFS(n);
		printf("Case %d:\n", ++test);
		cout << breaker << endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(isDominated[i][j]){
					cout << "|Y";
				}else{
					cout << "|N";
				}
			}
			cout << "|\n";
			cout << breaker << endl;
		}
	}
	return 0;
}

void DFS(int n){
	int off=-1;
	int u=0;
	off=-1;
	original.clear();
	DFSUtil(u, off);
	for(int i: original)
		isDominated[u][i]=true;
	for(int i=1; i<n; i++){
		if(original.count(i)){
			off=i;
			for(int k=1; k<n; k++){
				if(k==i){
					isDominated[i][k]=true;
					continue;
				}
				if(!original.count(k)){
					isDominated[i][k] = false;
					continue;
				}
				temp.clear();
				DFSUtil(u, off);
				visited.clear();visited.assign(n+2, false);
				if(temp.count(k)){
					isDominated[i][k] = false;
				}else{
					isDominated[i][k] = true;
				}
			}
		}
	}
	for(int i=1; i<n; i++){
		if(!original.count(i)){
			for(int j=0; j<n; j++){
				isDominated[j][i] = false;
			}
		}
	}
}

void DFSUtil(int u, int off){
	if(u==off)
		return;
	if(off==-1) OriVisited[u] = true;
	else visited[u] = true;
	if(off==-1) original.insert(u);
	else temp.insert(u);
	for(int v: adjList[u]){
		if(v==u)
			continue;
		if(off==-1){
			if(!OriVisited[v])
				DFSUtil(v, off);
		}else{
			if(!visited[v])
				DFSUtil(v, off);
		}
	}
}
