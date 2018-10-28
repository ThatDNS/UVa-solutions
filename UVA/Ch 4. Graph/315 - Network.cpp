// Problem: 315 - Network
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define pb push_back
vector<int> dfs_num, dfs_low, dfs_parent;
int dfsRoot, rootChildren, dfsCounter;
vector<bool> arti_vert;
vector<vector<int> > adjList;
void articulationPointAndBridge(int u);
int main(){
	short int N;
	int u, v;
	char c;
	while(cin >> N && N!=0){
		dfs_num.clear(); dfs_low.clear(); dfs_parent.clear(); arti_vert.clear(); adjList.clear();
		dfsCounter=0;
		dfs_num.assign(N+2, -1);
		dfs_low.assign(N+2, 0);
		dfs_parent.assign(N+2, 0);
		arti_vert.assign(N+2, false);
		adjList.assign(N+2, vector<int>());
		while(scanf("%d", &u)==1 && u){
			while(scanf("%d%c", &v, &c)==2){
				adjList[u].pb(v);
				adjList[v].pb(u);
				if(c=='\n')
					break;
			}
		}
		for(int i=1; i<=N; i++){
			if(dfs_num[i] == -1){
				dfsRoot = i;
				rootChildren = 0;
				articulationPointAndBridge(i);
				arti_vert[i] = (rootChildren>1);
			}
		}
		int no=0;
		for(int i=1; i<=N; i++){
			if(arti_vert[i])
				++no;
		}
		cout << no << endl;
	}
	return 0;
}

void articulationPointAndBridge(int u){
	dfs_low[u] = dfsCounter;
	dfs_num[u] = dfsCounter;
	++dfsCounter;
	for(int v: adjList[u]){
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
			if(u==dfsRoot) rootChildren++;
			articulationPointAndBridge(v);
			if(dfs_low[v] >= dfs_num[u])
				arti_vert[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

