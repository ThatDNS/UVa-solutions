// LIS ALONG WITH PATH
/* Sample Input:
8
-7 10 9 2 3 8 8 1
*/
// Usual DP soln is O(n^2).
// This is O(nlogn) solution for LIS.
// Reference: https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
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

int LIS(int arr[]);
int findPosition(int l, int r, int val);
void print();
vi lastEls;
vector<vi> allPaths;
int n; //size

int main(){
	cin >> n;
	int arr[n+2];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	int lis = LIS(arr);
	printf("Length: %d\n", lis);
	int last = allPaths.size()-1;
	for(int i=0; i<lis; i++){
		cout << allPaths[last][i] << " ";
	}cout << endl;
	return 0;
}

int LIS(int arr[]){
	if(n==0) return 0;
	lastEls.assign(n+2, 0);
	int length = 1;
	lastEls[0] = arr[0];
	allPaths.pb(lastEls);
	for(int i=1; i<n; i++){
		if(arr[i] < lastEls[0]){ //new smallest element
			lastEls[0] = arr[i];
			allPaths[0] = lastEls;
		}else if(arr[i] > lastEls[length-1]){ //new largest element
			lastEls[length++] = arr[i];
			allPaths.pb(lastEls);
		}else{ //new element is somewhere in between
			lastEls[findPosition(-1, length-1, arr[i])] = arr[i];
			allPaths[findPosition(-1, length-1, arr[i])] = lastEls;
		}
	}
	return length;
}

int findPosition(int l, int r, int val){
	int mid;
	while(r-l > 1){
		mid = l + (r-l)/2;
		if(lastEls[mid] >= val)
			r = mid;
		else
			l = mid;
	}
	return r;
}

