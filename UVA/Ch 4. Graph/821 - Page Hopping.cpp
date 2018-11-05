// Problem: 821 - Page Hopping
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
#define INF 1e9 // 10^9xs

int main(){
	int u, v, n, cases=0;
	while(cin >> u >> v && (u!=0 || v!=0)){
		n = -1;
		int AdjMat[102][102], paths=0;
		float avg=0, sum=0;
		for(int i=0; i<101; i++){
			for(int j=0; j<101; j++){
					AdjMat[i][j] = INF;
			}
			AdjMat[i][i] = 0;
		}
		AdjMat[u][v] = 1;
		n = max(n, u); n = max(n, v);
		while(cin >> u >> v && (u!=0 || v!=0)){
			AdjMat[u][v] = 1;
			n = max(n, u); n = max(n, v);
		}
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k]+AdjMat[k][j]);
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(AdjMat[i][j]!=0 && AdjMat[i][j]!=INF){
					++paths; sum += AdjMat[i][j];
				}
			}
		}
		avg = sum/paths;
		printf("Case %d: average length between pages = %.3f clicks\n", ++cases, avg);
	}
	return 0;
}
