// Problem: 10003 - Cutting Sticks
/**
 *	Author: DNS404
 **/
#include <bits/stdc++.h>
using namespace std;
/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
/*---------------Bitmask---------------*/
#define setBit(S, pos) (S |= (1 << pos))
#define resetBit(S, pos) (S &= ~(1 << pos))
#define checkBit(S, pos) (S & (1 << pos))
#define toggleBit(S, pos) (S ^= (1 << pos))
#define lowBit(S) (S & (-S)) //get least bit that is 1
/*-------------------------------------*/
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;
#define EPS 1e-9 // 10^-9
#define pb push_back
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define For0(i,n) for(int i=0; i<n; i++)
#define For(i,a,b) for(int i=0; i<n; i++)
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

int table[55][55], arr[55];
int cut(int left, int right);

int main(){
	int l, n;
	while(cin >> l && l){
		cin >> n;
		arr[0] = 0;
		for(int i=1; i<=n; i++)
			scanf("%d", &arr[i]);
		arr[n+1] = l;
		memset(table, -1, sizeof(table));
		printf("The minimum cutting is %d.\n", cut(0, n+1));
	}
	return 0;
}

int cut(int left, int right){
	if(left+1 == right)
		return 0;
	if(table[left][right]!=-1){
		return table[left][right];
	}
	int ans = INT_MAX;
	for(int i=left+1; i<right; i++){
		ans = min(ans, cut(left, i) + cut(i, right) + (arr[right]-arr[left]));
	}
	return table[left][right] = ans;
}

