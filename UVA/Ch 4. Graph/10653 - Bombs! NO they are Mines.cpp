// Problem: 10653 - Bombs! NO they are Mines!!
/*Concept:
I simply converted the grid into a graph and then ran DFS onto it. The code is pretty simple.
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

vector<vi> adjList;
vb visited;
vi dist;
void BFS(int u);

int main(){
	short int R, C, rows, r, n, c, sR, sC, dR, dC;
	int source, desti;
	while(cin >> R >> C && (R!=0 || C!=0)){
		cin >> rows; adjList.clear();
		visited.clear(); dist.clear();
		int mat[R+2][C+2];
		adjList.assign(R*C+2, vi());
		visited.assign(R*C+2, false);
		dist.assign(R*C+2, 0);
		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++)
				mat[i][j]=1;
		for(int i=0; i<rows; i++){
			cin >> r >> n;
			for(int j=0; j<n; j++){
				cin >> c;
				mat[r][c] = 0;
			}
		}
		cin >> sR >> sC;
		cin >> dR >> dC;

		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				// i+i*(C-1)+j tells the graph node number(0 to R*C-1).
				if(mat[i][j]==1 && j!=0) //back
					if(mat[i][j-1]==1)
						adjList[i+i*(C-1)+j].pb(i+i*(C-1)+j - 1);
				if(mat[i][j]==1 && i!=0) //up
					if(mat[i-1][j]==1)
						adjList[i+i*(C-1)+j].pb(i+i*(C-1)+j - C);
				if(mat[i][j]==1 && j!=C-1) //front
					if(mat[i][j+1]==1)
						adjList[i+i*(C-1)+j].pb(i+i*(C-1)+j + 1);
				if(mat[i][j]==1 && i!=R-1) //down
					if(mat[i+1][j]==1)
						adjList[i+i*(C-1)+j].pb(i+i*(C-1)+j + C);
			}
		}
		source = sR+sR*(C-1)+sC; desti = dR+dR*(C-1)+dC;
		BFS(source);
		cout << dist[desti] << endl;
	}
}

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int j: adjList[v]){
			if(!visited[j]){
				dist[j] = dist[v]+1;
				q.push(j);
				visited[j] = true;
			}
		}
	}
}

