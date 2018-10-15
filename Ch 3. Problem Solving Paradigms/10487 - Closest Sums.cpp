// Problem: 10487 - Closest Sums
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
vector<int> GenerateSums(long long arr[], int n);
int main(){
	short int n, m, count=0;
	int query, diff=INT_MAX, ans;
	while(cin >> n && n!=0){
		printf("Case %d:\n", ++count);
		long long arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];
		vector<int> sum = GenerateSums(arr, n);
		cin >> m;
		for(int i=0; i<m; i++){
			cin >> query;
			diff=INT_MAX;
			for(int j=0; j<sum.size(); j++){
				if(diff > abs(query-sum[j])){
					ans = sum[j];
					diff = abs(query-sum[j]);
				}
			}
			printf("Closest sum to %d is %d.\n", query, ans);
		}
	}
	return 0;
}
vector<int> GenerateSums(long long arr[], int n){
	vector<int> vec;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
			vec.push_back(arr[i]+arr[j]);
	}
	return vec;
}
