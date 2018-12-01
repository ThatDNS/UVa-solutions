// Problem: 11553 - Grid Game
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
	short int t, n, temp;
	cin >> t;
	while(t--){
		cin >> n;
		short int M[n+2][n+2];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> temp;
				M[i][j] = temp;
			}
		}
		int arr[n+2], netTotal=INT_MAX, tempTotal;
		for(int i=0; i<n; i++)
			arr[i] = i;
		do{
			tempTotal=0;
			for(int i=0; i<n; i++)
				tempTotal += M[i][arr[i]];
			if(netTotal >= tempTotal)
				netTotal = tempTotal;
		}while(next_permutation(arr, arr+n));
		printf("%d\n", netTotal);
	}
	return 0;
}
