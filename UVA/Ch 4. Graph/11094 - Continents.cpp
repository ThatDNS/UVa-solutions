// Problem: 11094 - Continents
/*Concept:
Simple problem. Just create the graph and run BFS. After every loop, calculate the
number of vertices. Return the connected component with maximum vertices.
*/
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define pb push_back
vector<int> Xcords;
vector<int> Ycords;
vector<bool> visited;
int arr[22][22], curr=0, kingPos;
int findVert(int x, int y);
void addEdge(int u, int v);
vector<vector<int> > graph;
vector<int> tempStor;
void BFS(int u);
int main(){
	short int m, n, posX, posY, a, b;
	string s;
	char l, t;
	while(cin >> m >> n){
		Xcords.clear(); Ycords.clear();
		graph.clear(); curr=0; visited.clear();
		string ss[m+2];
		for(int i=0; i<m; i++){
			cin >> ss[i];
		}
		cin >> posX >> posY;
		l = ss[posX][posY];
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				t = ss[i][j];
				if(t!=l)
					arr[i][j] = 0;
				else if(t==l){
					arr[i][j] = 1;
					Xcords.pb(i);
					Ycords.pb(j);
					++curr;
				}
			}
		}
		graph.assign(curr+2, vector<int>());
		visited.assign(curr+2, false);
		kingPos = findVert(posX, posY);
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(j!=n-1){
					if(arr[i][j]==1 && arr[i][j+1]==1){
						a = findVert(i, j);
						b = findVert(i, j+1);
						addEdge(a, b);
					}
				}else{
					if(arr[i][j]==1 && arr[i][0]==1){
						a = findVert(i, j);
						b = findVert(i, 0);
						addEdge(a, b);
					}
				}
				if(i!=m-1){
					if(arr[i][j]==1 && arr[i+1][j]==1){
						a = findVert(i, j);
						b = findVert(i+1, j);
						addEdge(a, b);
					}
				}
			}
		}
		bool KING=false;
		int max = INT_MIN;
		for(int i=0; i<curr; i++){
			KING=false;
			if(!visited[i])
				BFS(i);
			for(int j: tempStor){
				if(j==kingPos){
					KING=true;
					break;
				}
			}
			if(!KING){
				if((int)tempStor.size() > max)
					max = (int)tempStor.size();
			}
			tempStor.clear();
		}
		if(max < 0)
			max = 0;
		cout << max << endl;
	}
	return 0;
}

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		tempStor.pb(v);
		for(auto it=graph[v].begin(); it!=graph[v].end(); ++it){
			if(!visited[*it]){
				q.push(*it);
				visited[*it] = true;
			}
		}
	}
}

int findVert(int x, int y){
	for(int i=0; i<Xcords.size(); i++){
		if(Xcords[i] == x && Ycords[i] == y)
			return i;
	}
	return -1;
}

void addEdge(int u, int v){
	graph[u].pb(v);
	graph[v].pb(u);
}


