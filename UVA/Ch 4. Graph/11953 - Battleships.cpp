// Problem: 11953 - Battleships
/*Concept:
Simply run flood fill algorithm.
There's a catch! Don't consider SE,SW,NE,NW directions.
Also, remember that @ was earlier part of a ship. So, x@x is one ship, NOT two.
*/
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define pb push_back
// S,E,N,W neighbors
int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1};
void floodfill(int r, int c, char c1, char c2);
int N;
char grid[105][105];
int main(){
	short int t, curCase=0;
	int count, temp;
	char c;
	cin >> t;
	while(t--){
		count = 0;
		cin >> N;
		string s;
		for(int i=0; i<N; i++){
			cin >> s;
			for(int j=0; j<N; j++)
				grid[i][j] = s[j];
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				c = grid[i][j];
				if(c=='x'){
					floodfill(i, j, c, '.');
					count++;
				}
			}
		}
		printf("Case %d: %d\n", ++curCase, count);
	}
	return 0;
}

void floodfill(int r, int c, char c1, char c2){
	if(r<0 || r>=N || c<0 || c>=N || grid[r][c]==c2)
		return;
	if(grid[r][c] == '@')
		grid[r][c] = c1;
	if(grid[r][c] != c1)
		return;
	grid[r][c] = c2;
	for(int i=0; i<4; i++)
		floodfill(r + dr[i], c + dc[i], c1, c2);
}


