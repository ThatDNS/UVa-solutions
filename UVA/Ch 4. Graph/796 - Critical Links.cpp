// Problem: 796 - Critical Links
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define pb push_back
vector<int> dfs_num, dfs_low, dfs_parent, uu, vv;
int dfsRoot, rootChildren, dfsCounter, counter=0;
vector<bool> arti_vert;
vector<vector<int> > adjList;
void articulationPointAndBridge(int u);
void bubbleSort();
int main(){
	int n;
	int u, a, v;
	while(cin >> n){
		dfs_num.clear(); dfs_low.clear(); dfs_parent.clear(); arti_vert.clear(); adjList.clear();
		dfsCounter=0; counter=0; uu.clear(); vv.clear();
		dfs_num.assign(n+2, -1);
		dfs_low.assign(n+2, 0);
		dfs_parent.assign(n+2, 0);
		arti_vert.assign(n+2, false);
		adjList.assign(n+2, vector<int>());
		for(int i=0; i<n; i++){
			scanf("%d (%d)", &u, &a);
			fflush(stdin);
			for(int i=0; i<a; i++){
				cin >> v;
				adjList[u].pb(v);
				adjList[v].pb(u);
			}
		}
		for(int i=0; i<n; i++){
			if(dfs_num[i] == -1){
				dfsRoot = i;
				rootChildren = 0;
				articulationPointAndBridge(i);
				arti_vert[i] = (rootChildren>1);
			}
		}
		bubbleSort();
		printf("%d critical links\n", counter);
		for(int i=0; i<uu.size(); i++){
			printf("%d - %d\n", uu[i], vv[i]);
		}
		cout << endl;
	}
	return 0;
}

void bubbleSort(){
	int temp, n = uu.size();
	for(int i = 0; i < n-1; i++){    
    for(int j = 0; j < n-i-1; j++){
			if(uu[j] > uu[j+1]){
				temp = uu[j];
				uu[j] = uu[j+1];
				uu[j+1] = temp;
				temp = vv[j];
				vv[j] = vv[j+1];
				vv[j+1] = temp;
			}else if(uu[j] == uu[j+1]){
				if(vv[j] > vv[j+1]){
					temp = uu[j];
					uu[j] = uu[j+1];
					uu[j+1] = temp;
					temp = vv[j];
					vv[j] = vv[j+1];
					vv[j+1] = temp;
				}
			}
		}
	}
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
			if(dfs_low[v] > dfs_num[u]){
				++counter;
				if(u<v){
					uu.pb(u);
					vv.pb(v);
				}else{
					uu.pb(v);
					vv.pb(u);
				}
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

