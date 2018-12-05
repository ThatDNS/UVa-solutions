// Longest Increasing Subsequence ALONG WITH PATH
/* Sample Input:
8
-7 10 9 2 3 8 8 1
*/
// Usual DP soln is O(n^2).
// This is O(nlogn) solution for LIS.
// Reference(for concept): https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// Just remember three conditions given on this link.
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

// arr: Stores the numbers
// P[i]: Stores the index of the prev element of ith element of lastEls
int arr[1000000], P[1000000];
// lastEls[i]: Stores the last value in subsequence of length i
// L_id[i]: Stores the index of this value in arr.
int lastEls[1000000], L_id[1000000];
void print(int i);

int main(){
	int no, i=0, length=0, end=0;
	while(cin >> no){
		arr[i] = no;
		int pos = lower_bound(lastEls, lastEls+length, arr[i])-lastEls;
		lastEls[pos] = arr[i];
		L_id[pos] = i;
		P[i] = pos>0 ? L_id[pos-1] : -1;
		if(pos == length){
			length++;
			end = i;
		}
		++i;
	}
	printf("Length: %d\n", length);
	print(end);
	printf("\n");
	return 0;
}

void print(int i){
	if(i < 0) return;
	print(P[i]);
	printf("%d ", arr[i]);
}

