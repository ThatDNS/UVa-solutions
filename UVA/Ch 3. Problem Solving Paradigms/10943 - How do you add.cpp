// Problem: 10943 - How do you add?
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

int main(){
	int n, k;
	long long arr[102][102];
	memset(arr, 0, sizeof(arr));
	for(int i=1; i<=100; i++){ //k
		for(int j=0; j<=100; j++){ //n
			if(i==1){
				arr[i][j] = 1;
				continue;
			}
			for(int p=0; p<=j; p++){
				arr[i][j] += arr[i-1][p];
				arr[i][j] %= 1000000;
			}
		}
	}
	while(cin >> n >> k && n){
		cout << arr[k][n] << endl;
	}
	return 0;
}

