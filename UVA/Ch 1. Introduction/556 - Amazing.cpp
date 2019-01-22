// Problem: 556 - Amazing

/* Algo:
if wall is present on right:
	if robot can move forward:
		move forward;
	else:
		turn left;
else:
	turn right;
*/

/**
 *	Author: DNS404
 **/
#include <bits/stdc++.h>
using namespace std;
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
#define quick ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

int Right(int dir);
int Left(int dir);
int posX(int j, int dir);
int posY(int i, int dir);

int main(){
	int b, w, first, dir;
	int zero, one, two, three, four;
	string s, aa, bb, cc, dd, ee;
	char c;
	while(cin >> b >> w){
		zero=0; one=0; two=0; three=0; four=0;
		getline(cin, s);
		if(b==0 && w==0)
			break;
		int maze[b+5][w+5];
		int NoVisit[b+5][w+5];
		for(int i=1; i<=b; i++){
			getline(cin, s);
			for(int j=0; j<s.length(); j++){
				c = s[j];
				if(c == '1')
					maze[i][j+1] = 1;
				else if(c == '0')
					maze[i][j+1] = 0;
			}
		}

		//wall in surrounding:
		for(int i=0; i<=w+1; i++){
			maze[0][i] = 1;
		}
		for(int i=0; i<=w+1; i++){
			maze[b+1][i] = 1;
		}
		for(int i=0; i<=b+1; i++){
			maze[i][0] = 1;
		}
		for(int i=0; i<=b+1; i++){
			maze[i][w+1] = 1;
		}

		for(int i=1; i<=b; i++){
			for(int j=1; j<=w; j++)
				NoVisit[i][j] = 0;
		}

		int i=b, j=1;
		first=1; dir=1;
		//1: E, 2: N, 3: W, 4: S
		while((i!=b || j!=1) || first==1){
			//check wall on right
			if(maze[posY(i, Right(dir))][posX(j, Right(dir))] == 1){
				//if can move forward
				if(maze[posY(i, dir)][posX(j, dir)] != 1){
					//move forward
					++NoVisit[i][j];
					i = posY(i, dir);
					j = posX(j, dir);
					if(first == 1) first = 0;
				}else{
					//turn left
					dir = Left(dir);
				}
			}else{
				//turn right
				dir = Right(dir);
				++NoVisit[i][j];
				i = posY(i, dir);
				j = posX(j, dir);
			}
		}

		for(int i=1; i<=b; i++){
			for(int j=1; j<=w; j++){
				if(maze[i][j] == 0){
					if(NoVisit[i][j] == 0)
						++zero;
					else if(NoVisit[i][j] == 1)
						++one;
					else if(NoVisit[i][j] == 2)
						++two;
					else if(NoVisit[i][j] == 3)
						++three;
					else if(NoVisit[i][j] == 4)
						++four;
				}
			}
		}
		aa = to_string(zero);
		bb = to_string(one);
		cc = to_string(two);
		dd = to_string(three);
		ee = to_string(four);
		cout << setw(3) << right << aa;
		cout << setw(3) << right << bb;
		cout << setw(3) << right << cc;
		cout << setw(3) << right << dd;
		cout << setw(3) << right << ee;
		cout << endl;
	}
	return 0;
}

int Right(int dir){
	if(dir>1)
		return dir-1;
	else if(dir == 1)
		return 4;
	return 0;
}

int Left(int dir){
	if(dir<4)
		return dir+1;
	else if(dir == 4)
		return 1;
	return 0;
}

int posX(int j, int dir){
	if(dir == 1){
		return j+1;
	}else if(dir == 2){
		return j;
	}else if(dir == 3){
		return j-1;
	}else if(dir == 4){
		return j;
	}
	return 0;
}

int posY(int i, int dir){
	if(dir == 1){
		return i;
	}else if(dir == 2){
		return i-1;
	}else if(dir == 3){
		return i;
	}else if(dir == 4){
		return i+1;
	}
	return 0;
}


