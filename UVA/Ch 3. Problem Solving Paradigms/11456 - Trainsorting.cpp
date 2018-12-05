// Problem: 11456 - Trainsorting
// It was difficult to think about this one.
/* Concept:


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

int main(){
	int tc, val1, val2;
	short int n;
	int cars[2002], LIS[2002], LDS[2002];
	cin >> tc;
	while(tc--){
		cin >> n;
		if(n==0){
			printf("0\n"); continue;
		}
		for(int i=0; i<n; i++)
			scanf("%d", &cars[i]);
		for(int i=n-1; i>=0; i--){
			LIS[i] = 1;
			LDS[i] = 1;
			for(int j=i+1; j<n; j++){
				if(cars[i] < cars[j])
					LIS[i] = max(LIS[i], LIS[j]+1);
				if(cars[i] > cars[j])
					LDS[i] = max(LDS[i], LDS[j]+1);
			}
		}
		int temp = INT_MIN;
		for(int i=0; i<n; i++){
			temp = max(temp ,LIS[i]+LDS[i]-1);
		}
		cout << temp << endl;
	}
	return 0;
}
