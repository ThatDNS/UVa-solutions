// Problem: 10284 - Chessboard in FEN
/**
 *	Author: Fallen_Cryptic
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

int board[16][16];
const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};
const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1};
const int fxK[]={0, 0, 1,-1,-1, 1,-1, 1};
const int fyK[]={-1, 1, 0, 0, 1, 1,-1,-1};
void attR(int i, int j);
void attN(int i, int j);
void attB(int i, int j);
void attK(int i, int j);
void attP(int i, int j);

int main(){
	string s;
	int no, count=0;
	char c;
	while(getline(cin, s)){
		count=0;
		memset(board, 0, sizeof(board));
		for(int k=0, i=2, j=2; k<s.length(); k++){
			c = s[k];
			if(c == '/'){
				++i; j=2;
				continue;
			}
			if(c=='p')
				board[i][j] = 2;
			else if(c=='P')
				board[i][j] = 9;
			else if(c=='r'||c=='R')
				board[i][j] = 3;
			else if(c=='n'||c=='N')
				board[i][j] = 4;
			else if(c=='b'||c=='B')
				board[i][j] = 5;
			else if(c=='q'||c=='Q')
				board[i][j] = 6;
			else if(c=='k'||c=='K')
				board[i][j] = 7;
			else{
				no = (int)c - 48;
				while(no--){
					board[i][j] = 0;
					++j;
				}
				--j;
			}
			++j;
		}

		for(int i=2; i<=9; i++){
			for(int j=2; j<=9; j++){
				if(board[i][j]!=0 && board[i][j]!=1){
					if(board[i][j] == 3){
						attR(i, j);
					}else if(board[i][j] == 4){
						attN(i, j);
					}else if(board[i][j] == 5){
						attB(i, j);
					}else if(board[i][j] == 6){
						attR(i, j);
						attB(i, j);
					}else if(board[i][j] == 7){
						attK(i, j);
					}else if(board[i][j] == 2){
						attP(i, j);
					}else if(board[i][j] == 9){
						attP(i, j);
					}
				}
			}
		}

		for(int i=2; i<=9; i++){
			for(int j=2; j<=9; j++){
				if(board[i][j]==0)
					++count;
			}
		}
		cout << count << endl;

	}
	return 0;
}

void attR(int i, int j){
	for(int I=i-1; I>=2; I--){
		if(board[I][j]!=0 && board[I][j]!=1)
			break;
		board[I][j] = 1;
	}
	for(int I=i+1; I<=9; I++){
		if(board[I][j]!=0 && board[I][j]!=1)
			break;
		board[I][j] = 1;
	}
	for(int J=j-1; J>=2; J--){
		if(board[i][J]!=0 && board[i][J]!=1)
			break;
		board[i][J] = 1;
	}
	for(int J=j+1; J<=9; J++){
		if(board[i][J]!=0 && board[i][J]!=1)
			break;
		board[i][J] = 1;
	}
}

void attN(int i, int j){
	for(int I=0; I<8; I++){
		if(board[i+fx[I]][j+fy[I]]==0)
			board[i+fx[I]][j+fy[I]] = 1;	
	}
}

void attB(int i, int j){
	for(int I=i-1, J=j-1; I>=2 && J>=2; I--, J--){
		if(board[I][J]!=0 && board[I][J]!=1)
			break;
		board[I][J] = 1;
	}
	for(int I=i-1, J=j+1; I>=2 && J<=9; I--, J++){
		if(board[I][J]!=0 && board[I][J]!=1)
			break;
		board[I][J] = 1;
	}
	for(int I=i+1, J=j-1; I<=9 && J>=2; I++, J--){
		if(board[I][J]!=0 && board[I][J]!=1)
			break;
		board[I][J] = 1;
	}
	for(int I=i+1, J=j+1; I<=9 && J<=9; I++, J++){
		if(board[I][J]!=0 && board[I][J]!=1)
			break;
		board[I][J] = 1;
	}
}

void attK(int i, int j){
	for(int I=0; I<8; I++){
		if(board[i+fxK[I]][j+fyK[I]]==0)
			board[i+fxK[I]][j+fyK[I]] = 1;	
	}
}

void attP(int i, int j){
	int I, J;
	if(board[i][j] == 2){
		I=i+1; J=j+1;
		if(board[I][J]==0)
			board[I][J] = 1;
		I=i+1; J=j-1;
		if(board[I][J]==0)
			board[I][J] = 1;
	}else if(board[i][j] == 9){
		I=i-1; J=j+1;
		if(board[I][J]==0)
			board[I][J] = 1;
		I=i-1; J=j-1;
		if(board[I][J]==0)
			board[I][J] = 1;
	}
}
