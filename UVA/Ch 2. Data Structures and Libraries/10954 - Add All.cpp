// Problem: 10954 - Add All
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, no, sum;
	while(cin >> N && N!=0){
		// Creating Min Heap
		priority_queue<int, vector<int>, greater<int> > nums;
		int ans=0;
		for(int i=0; i<N; i++){
			cin >> no;
			nums.push(no);
		}
		sum=0;
		while(nums.size() > 1){
			sum = nums.top();
			nums.pop();
			sum += nums.top();
			nums.pop();
			ans += sum;
			nums.push(sum);
		}
		cout << ans << endl;
	}
	return 0;
}
