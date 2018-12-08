// Problem: 990 - Diving for Gold
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

int main(){
	int t, w, n, cap, flag=0;
	vi chosen;
	while(cin >> t >> w){
		if(flag==1) printf("\n");
		if(flag==0) flag=1;
		chosen.clear();
		cin >> n;
		int D[n+2], V[n+2], T[n+2][t+2];
		for(int i=0; i<n; i++)
			scanf("%d %d", &D[i], &V[i]);

		for(int i=0; i<n; i++){
			cap = 3 * w * D[i];
			for(int j=0; j<=t; j++){
				if(j >= cap){
					if(i!=0)
						T[i][j] = max(V[i]+T[i-1][j-cap], T[i-1][j]);
					else
						T[i][j] = V[i];
				}else{
					if(i!=0)
						T[i][j] = T[i-1][j];
					else
						T[i][j] = 0;
				}
			}
		}

		int i=n-1, j=t;
		printf("%d\n", T[i][j]);
		while(i>=0 && T[i][j]!=0){
			if(T[i][j] == T[i-1][j]){
				i--;
			}else{
				chosen.pb(i);
				j -= 3*w*D[i];
				i--;
			}
		}

		printf("%d\n", (int)chosen.size());
		for(int i=(int)chosen.size()-1; i>=0; i--){
			printf("%d %d\n", D[chosen[i]], V[chosen[i]]);
		}
	}
	return 0;
}

