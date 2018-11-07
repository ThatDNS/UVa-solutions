// Problem: 104 - Arbitrage
// It says level 2 but I think it was a difficult question. Had to take hints from few blog posts.
// Checkout this post for the logic behind this solution: https://abitofcs.blogspot.com/2014/08/a-bit-of-uva-uva-104-arbitrage.html
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
void printp(int i, int j);
float AdjMat[25][25][25];
int p[25][25][25];
int main(){
	int n;
	stack<int> S;
	while(cin >> n){
		memset(AdjMat, 0, sizeof(AdjMat));
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j){
					AdjMat[i][j][0] = 1.0;
				}else{
					cin >> AdjMat[i][j][0];
				}
				p[i][j][0] = i;
			}
		}
		for(int s=1; s<n; s++){ //3d part is zero indexed
			for(int k=1; k<=n; k++)
				for(int i=1; i<=n; i++)
					for(int j=1; j<=n; j++){
						double temp = AdjMat[i][k][s-1]*AdjMat[k][j][0];
						if(temp > AdjMat[i][j][s]){
							AdjMat[i][j][s] = temp;
							p[i][j][s] = k;
						}
					}
		}
		int temp;
		bool found = false;
		for(int k=1; k<n && !found; k++){
			for(int i=1; i<=n && !found; i++){
				if(AdjMat[i][i][k] > 1.01){
					S.push(p[i][i][k]);
					for(int j=k-1; j>=0; j--)
						S.push(p[i][S.top()][j]);
					temp = S.top();
					while(!S.empty()){
						cout << S.top() << " ";
						S.pop();
					}
					cout << temp << endl;
					found = true;
				}
			}
		}
		if(!found)
			printf("no arbitrage sequence exists\n");
	}
	return 0;
}
