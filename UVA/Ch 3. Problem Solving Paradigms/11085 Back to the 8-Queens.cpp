// Problem: 11085 Back to the 8-Queens (2 WAYS)
/**
 *	Author: DNS-404
 **/

// WAY 1

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




/*  ANOTHER WAY: USING BACKTRACKING  */

// WAY 2

#include <bits/stdc++.h>
using namespace std;

int currRow[10]; // which row in index=col
int finalPos[100][10], ind=0; // all possible combinations
void placeIt(int row, int col);
bool canPlace(int row, int col);

int main(){
  int diff, temp, count=0;
  for(int r=1; r<=8; r++){
    clr(currRow, 1);
    placeIt(r, 1);
  }
  int p[10];
  while(cin>>p[0]>>p[1]>>p[2]>>p[3]>>p[4]>>p[5]>>p[6]>>p[7]){
    diff = INT_MAX;
    for(int i=0; i<ind; i++){ // O(92*8)
      temp = 0;
      for(int j=1; j<=8; j++){
        if(p[j-1] != finalPos[i][j])
          ++temp;
      }
      diff = min(temp, diff);
    }
    printf("Case %d: %d\n", ++count, diff);
  }
  return 0;
}

void placeIt(int row, int col){
  currRow[col] = row;
  //terminate
  if(col == 8){
    for(int i=1; i<=8; i++)
      finalPos[ind][i] = currRow[i];
    ++ind;
    return;
  }

  for(int r=1; r<=8; r++){ //for next col
    if(canPlace(r, col+1))
      placeIt(r, col+1);
  }
}

bool canPlace(int row, int col){
  for(int c=1; c<col; c++){
    if(currRow[c] == row || abs(row-currRow[c]) == abs(col-c))
      return false;
  }
  return true;
}

