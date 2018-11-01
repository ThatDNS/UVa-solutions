// Problem: 429 - Word Transformation
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
bool countDiff(string a, string b);
vector<vi> adjList;
vb visited;
vector<int> dist;
map<string, int> s_i;
map<string, int>::iterator s_i_it;
map<int, string> i_s;
map<int, string>::iterator i_s_it;
vector<string> verts;

int main(){
	int n, count=1, u, v, flag=0;
	string s, s1, s2;
	cin >> n;
	while(n--){
		if(flag==1) cout << "\n";
		if(flag==0) flag=1;
		count = 1; verts.clear(); adjList.clear();
		s_i.clear(); i_s.clear();
		while(cin >> s && s!="*"){
			if(s_i.count(s)==0){
				s_i.insert(pair<string, int> (s, count));
				i_s.insert(pair<int, string> (count, s));
				++count;
			}
			verts.pb(s);
		}
		u = verts.size();
		adjList.assign(u+2, vi());
		for(int i=0; i<(int)verts.size(); i++){
			for(int j=i+1; j<(int)verts.size(); j++){
				s1 = verts[i]; s2 = verts[j];
				s_i_it = s_i.find(s1);
				u = s_i_it->second;
				s_i_it = s_i.find(s2);
				v = s_i_it->second;
				if(countDiff(s1,s2)){
					adjList[u].pb(v); adjList[v].pb(u);
				}
			}
		}
		cin.ignore();
		while(getline(cin, s) && s!=""){
			s1 = s.substr(0, s.find(" "));
			s2 = s.substr(s.find(" ")+1, s.length());
			visited.clear(); dist.clear();
			visited.assign((int)verts.size()+2, false);
			dist.assign((int)verts.size()+2, 0);
			s_i_it = s_i.find(s1);
			u = s_i_it->second;
			s_i_it = s_i.find(s2);
			v = s_i_it->second;
			BFS(u);
			cout << s1 << " " << s2 << " " << dist[v] << endl;
		}
	}
	return 0;
}

bool countDiff(string a, string b){
	if(a.length() != b.length())
		return false;
	int i=0, j=0, diff=0;
	while(i<=a.length()){
		if(a[i] != b[j])
			++diff;
		++i; ++j;
	}
	if(diff==1)
		return true;
	return false;
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
