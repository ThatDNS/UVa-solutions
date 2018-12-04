// Problem: 108 - Maximum Sum
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
	short int n;
	int arr[102][102], subRect, maxSubRect;
	while(cin >> n){
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				scanf("%d", &arr[i][j]);
				if(i>0) arr[i][j] += arr[i-1][j];
				if(j>0) arr[i][j] += arr[i][j-1];
				if(i>0 && j>0) arr[i][j] -= arr[i-1][j-1];
			}
		maxSubRect = -127*100*100;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				for(int k=i; k<n; k++)
					for(int l=j; l<n; l++){
						subRect = arr[k][l];
						if(i>0) subRect -= arr[i-1][l];
						if(j>0) subRect -= arr[k][j-1];
						if(i>0 && j>0) subRect += arr[i-1][j-1];
						maxSubRect = max(maxSubRect, subRect);
					}
		printf("%d\n", maxSubRect);

	}
	return 0;
}
