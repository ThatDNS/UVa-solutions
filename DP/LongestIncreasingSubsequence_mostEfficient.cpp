// Usual DP soln is O(n^2).
// This is O(nlogn) solution for LIS.
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
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
int n; //size

int main(){
	cin >> n;
	int arr[n+2];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	int lis = LIS(arr);
	printf("Length: %d\n", lis);
	//print();
	return 0;
}

int LIS(int arr[]){
	if(n==0) return 0;
	lastEls.assign(n+2, 0);
	int length = 1;
	lastEls[0] = arr[0];
	//print();
	for(int i=1; i<n; i++){
		//printf("Curr: %d\n", arr[i]);
		if(arr[i] < lastEls[0]){ //new smallest element
			//printf("Found new smallest! Changing %d to %d at 0\n", lastEls[0],arr[i]);
			lastEls[0] = arr[i];
			//print();
		}else if(arr[i] > lastEls[length-1]){ //new largest element
			//printf("Found new largest! Adding %d in place of %d at %d\n", arr[i],lastEls[length+1],length+1);
			lastEls[length++] = arr[i];
			//print();
		}else{ //new element is somewhere in between
			//printf("Was in between! Adding %d in place of %d at %d\n", arr[i],lastEls[findPosition(-1, length-1, arr[i])], findPosition(-1, length-1, arr[i]));
			lastEls[findPosition(-1, length-1, arr[i])] = arr[i];
			//print();
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

void print(){
	for(int i: lastEls)
		printf("%d ", i);
	printf("\n");
}
