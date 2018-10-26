// Problem: 11060 - Beverages
/*Concept:
You have to use Kahn’s algorithm to do topological sorting but there's a catch, which I learned it the hard way -_-
Basically, when you're checking for the next vertex with in-degree 0, if there are multiple
vertices then you have to always choose the one that appeared earlier in the input.
Hence, I'm using set rather than queue to sort the entries as I add them. I've commented that part in code.
Read it. It was simple but tricky.
*/
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<vector<int> > graph;
vector<bool> visited;
vector<int> inDegree, ans;
void BFS_setIndegree(int u);
int main(){
	short int n, m;
	map<string, int> vert;
	map<string, int>::iterator it1;
	map<int, string> oppVert;
	map<int, string>::iterator it2;
	int a, b, cases=1;
	string s1, s2;
	while(cin >> n){
		inDegree.clear(); ans.clear();
		vert.clear(); oppVert.clear();
		graph.clear(); visited.clear();
		visited.assign(n+2, false);
		inDegree.assign(n+2, 0);
		graph.assign(n+2, vector<int>());
		for(int i=0; i<n; i++){
			cin >> s1;
			vert.insert(pair<string, int> (s1, i+1));
			oppVert.insert(pair<int, string> (i+1, s1));
		}
		cin >> m;
		for(int i=0; i<m; i++){
			cin >> s1 >> s2;
			it1 = vert.find(s1);
			a = it1->second;
			it1 = vert.find(s2);
			b = it1->second;
			graph[a].pb(b);
		}
		for(int i=1; i<=n; i++){
			if(!visited[i])
				BFS_setIndegree(i);
		}
		set<int> Next;
		set<int>::iterator NextIT;
		for(int i=1; i<=n; i++){
			if(inDegree[i] == 0){
				// Inserting in set to get the vertices with lower index first. (its sorted!)
				Next.insert(i);
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order: ", cases++);
		visited.clear();
		visited.assign(n+2, false);
		while(!Next.empty()){
			NextIT=Next.begin();
			a = *NextIT;
			Next.erase(a);
			ans.pb(a);
			for(int v: graph[a]){
				--inDegree[v];
				if(inDegree[v]==0)
					Next.insert(v);
			}
		}
		for(int u=0; u<ans.size(); u++){
			it2 = oppVert.find(ans[u]);
			s1 = it2->second;
			if(u==ans.size()-1)
				cout << s1;
			else
				cout << s1 << " ";
		}
		cout << ".\n\n";
	}
	return 0;
}

void BFS_setIndegree(int u){
	visited[u] = true;
	for(int v: graph[u]){
		++inDegree[v];
	}
}