// Problem: 10443 - Rock, Scissors, Paper
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
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

bool check(int i, int j, bool turn);
char arr[104][104], brr[104][104];
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
int r, c;

int main(){
	int t, n, flag=0;
	bool turn;
	char ch;
	string s;
	cin >> t;
	while(t--){
		if(flag==1) cout << endl;
		if(flag==0) flag=1;
		cin >> r >> c >> n;
		getline(cin, s);
		for(int i=1; i<=r; i++){
			getline(cin, s);
			for(int j=0; j<(int)s.size(); j++){
				arr[i][j+1] = s[j];
			}
		}

		turn = false; // 0: put in brr, 1: put in arr
		while(n--){
			if(!turn){
				for(int i=1; i<=r; i++){
					for(int j=1; j<=c; j++){
						ch = arr[i][j];
						if(check(i, j, turn)){
							if(ch == 'R')
								brr[i][j] = 'P';
							else if(ch == 'S')
								brr[i][j] = 'R';
							else if(ch == 'P')
								brr[i][j] = 'S';
						}else{
							brr[i][j] = ch;
						}
					}
				}
			}else{
				for(int i=1; i<=r; i++){
					for(int j=1; j<=c; j++){
						ch = brr[i][j];
						if(check(i, j, turn)){
							if(ch == 'R')
								arr[i][j] = 'P';
							else if(ch == 'S')
								arr[i][j] = 'R';
							else if(ch == 'P')
								arr[i][j] = 'S';
						}else{
							arr[i][j] = ch;
						}
					}
				}
			}
			turn = !turn;
		}
		if(turn){
			for(int i=1; i<=r; i++){
				for(int j=1; j<=c; j++){
					cout << brr[i][j];
				}cout << endl;
			}
		}else{
			for(int i=1; i<=r; i++){
				for(int j=1; j<=c; j++){
					cout << arr[i][j];
				}cout << endl;
			}
		}
	}
	return 0;
}

bool check(int i, int j, bool turn){
	if(!turn){
		char c = arr[i][j], cc;
		for(int k=0; k<4; k++){
			cc = arr[i+fx[k]][j+fy[k]];
			if(c == 'R' && cc == 'P')
				return true;
			else if(c == 'S' && cc == 'R')
				return true;
			else if(c == 'P' && cc == 'S')
				return true;
		}
	}else{
		char c = brr[i][j], cc;
		for(int k=0; k<4; k++){
			cc = brr[i+fx[k]][j+fy[k]];
			if(c == 'R' && cc == 'P')
				return true;
			else if(c == 'S' && cc == 'R')
				return true;
			else if(c == 'P' && cc == 'S')
				return true;
		}
	}
	return false;
}
