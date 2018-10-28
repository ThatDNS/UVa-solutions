// Problem: 247 - Calling Circles
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vb vector<bool>
#define EPS 1e-9
#define pb push_back
vi dfs_low, dfs_num, S;
vb visited;
int dfsCounter, numSSC=0, counter=0;
vector<vector<int> > adjList;
vector<vector<int> > res;
map<int, string> i_s;
map<string, int> s_i;
map<int, string>::iterator it;
void tarjanSSC(int u);
int main(){
	int n, m, u, v;
	string s1, s2;
	map<string, int>::iterator it1;
	map<string, int>::iterator it2;
	map<int, int> records;
	int flag=0;
	while(cin >> n >> m && (n!=0 & m!=0)){
		if(flag==1)
			cout << endl;
		if(flag==0)
			flag=1;
		i_s.clear(); s_i.clear(); res.clear(); records.clear();
		dfsCounter=0; counter=0;
		dfs_num.clear(); dfs_low.clear(); visited.clear(); adjList.clear();
		dfs_num.assign(n+2, -1);
		dfs_low.assign(n+2, 0);
		visited.assign(n+2, false);
		adjList.assign(n+2, vector<int>());
		for(int i=0; i<m; i++){
			cin >> s1 >> s2;
			if(!s_i.count(s1)){
				i_s.insert(pair<int, string> (counter, s1));
				s_i.insert(pair<string, int> (s1, counter));
				++counter;
			}
			it1 = s_i.find(s1);
			if(!s_i.count(s2)){
				i_s.insert(pair<int, string> (counter, s2));
				s_i.insert(pair<string, int> (s2, counter));
				++counter;
			}
			it2 = s_i.find(s2);
			u = it1->second; v = it2->second;
			adjList[u].pb(v);
		}
		// for(auto itt=records.begin(); itt!=records.end(); itt++){
		// 	u = itt->first;
		// 	v = itt->second;
		// 	cout << u << " " << v << endl;
		// 	adjList[u].pb(v);
		// }
		printf("Calling circles for data set %d:\n", ++numSSC);
		for(int i=0; i<n; i++){
			if(dfs_num[i] == -1)
				tarjanSSC(i);
		}
		string s;
		set<int> temp;
		set<int>::iterator tempIT;
		for(int i=res.size()-1; i>=0; i--){
			temp.clear();
			for(int j: res[i]){
				temp.insert(j);
			}
			S.clear();
			for(tempIT = temp.begin(); tempIT!=temp.end(); ++tempIT){
				int v = *tempIT;
				S.pb(v);
			}
			for(int j=0, p; j<S.size(); j++){
				p = S[j];
				it = i_s.find(p);
				s = it->second;
				if(j!=S.size()-1)
					cout << s << ", ";
				else
					cout << s << "\n";
			}
		}
	}
	return 0;
}

void tarjanSSC(int u){
	dfs_low[u] = dfsCounter;
	dfs_num[u] = dfsCounter;
	S.pb(u);
	++dfsCounter;
	visited[u] = true;
	for(int v: adjList[u]){
		if(dfs_num[v] == -1)
			tarjanSSC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]){
		vector<int> vec;
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			vec.pb(v);
			if(u==v) break;
		}
		res.pb(vec);
	}
}
