// Problem: 11085 Back to the 8-Queens
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

vector<vi> allPos;
bool possible(int arr[]);

int main(){
	int arr[] = {1,2,3,4,5,6,7,8};
	vi temp;
	int t;
	do{
		if(possible(arr)){
			temp.clear();
			for(int i=0; i<8; i++){
				t = arr[i];
				temp.pb(t);
			}
			allPos.pb(temp);
		}
	}while(next_permutation(arr, arr+8));
	t=0;
	while(cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6] >> arr[7]){
		int minMove = INT_MAX, currMove;
		for(int i=0; i<(int)allPos.size(); i++){
			currMove=0;
			for(int j=0; j<(int)allPos[i].size(); j++){
				if(arr[j] != allPos[i][j])
					++currMove;
			}
			if(minMove > currMove)
				minMove = currMove;
		}
		printf("Case %d: %d\n", ++t, minMove);
	}
	return 0;
}

bool possible(int arr[]){
	for(int i=0; i<8; i++){
		for(int j=i+1; j<8; j++){
			if(arr[i] == arr[j])
				return false;
			if(abs(i-j) == abs(arr[i]-arr[j]))
				return false;
		}
	}
	return true;
}
