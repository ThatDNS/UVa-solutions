// Problem: 12455 - Bars
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
#define FOR0(i,n) for(int i=0;i<n;i++)
#define FORl(i,l,n) for(int i=l;i<n;i++)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
bool possible(int curr, vector<int> bars, int n, int sum);
int main(){
	short int t, n, p;
	int temp;
	vector<int> bars;
	cin >> t;
	while(t--){
		bars.clear();
		cin >> n;
		cin >> p;
		int dp[1010] = {}; // initialise to 0
		dp[0] = 1;
		for(int i=0; i<p; i++){
			cin >> temp;
			bars.push_back(temp);
			for(int j=n-temp; j>=0; j--){
				if(dp[j] && !dp[j+temp]){
					dp[j+temp] = 1;
				}
			}
		}
		if(dp[n])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

