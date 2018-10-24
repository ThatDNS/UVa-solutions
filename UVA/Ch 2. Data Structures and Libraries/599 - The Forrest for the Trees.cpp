// Problem: 599 - The Forrest for the Trees
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
map<char, bool> visited;
map<char, vector<char> > adjList;
map<char, vector<char> >::iterator adjListIT;
void BFS(map<char, bool>::iterator visIT);
vector<char> vertices;
int trees, acorns;
int main(){
	int t, vert=0;
	string s;
	cin >> t;
	map<char, bool>::iterator visIT;
	multimap<char, char> edges;
	multimap<char, char>::iterator edgeIT;
	char a, b;
	while(t--){
		visited.clear();
		adjList.clear(); edges.clear(); vertices.clear();
		vert=0; trees=0; acorns=0;
		while(cin >> s){
			a = s[0];
			if(a=='*')
				break;
			a = s[1];
			b = s[3];
			edges.insert(pair<char, char> (a, b));
		}
		cin >> s;
		for(int i=0; i<s.length(); i+=2){
			a = s[i];
			visited.insert(pair<char, bool> (a, false));
			vector<char> ch;
			vertices.pb(a);
			adjList.insert(pair<char, vector<char> > (a, ch));
		}
		for(edgeIT=edges.begin(); edgeIT!=edges.end(); ++edgeIT){
			a = edgeIT->first;
			b = edgeIT->second;
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		vertices.clear();
		for(visIT=visited.begin(); visIT!=visited.end(); visIT++){
			bool val = visIT->second;
			if(!val)
				BFS(visIT);
		}
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);

	}
	return 0;
}

void BFS(map<char, bool>::iterator visIT){
	queue<char> q;
	char ch = visIT->first;
	q.push(ch);
	visIT->second = true;
	while(!q.empty()){
		char v = q.front();
		q.pop();
		vertices.pb(v);
		adjListIT = adjList.find(v);
		for(char j: adjListIT->second){
			map<char, bool>::iterator tempVis;
			tempVis = visited.find(j);
			bool isVisited = tempVis->second;
			if(!isVisited){
				q.push(j);
				tempVis->second = true;
			}
		}
	}
	if(vertices.size() == 1){
		++acorns;
	}else{
		++trees;
	}
	vertices.clear();
	return;
}
