// Problem: 10813 - Traditional BINGO
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

bool checked[6][6];
int val[6][6], countt;
bool check();

int main(){
	int n, temp;
	map<int, ii> where;
	map<int, ii>::iterator it;
	ii abc;
	vi input;
	cin >> n;
	while(n--){
		input.clear(); where.clear();
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(i==2 && j==2){
					val[i][j] = 0;
					checked[i][j] = true;
				}
				else{
					scanf("%d", &temp);
					val[i][j] = temp;
					checked[i][j] = false;
					abc.first = i; abc.second = j;
					where.insert(pair<int, ii> (temp, abc));
				}
			}
		}
		for(int i=0; i<75; i++){
			cin >> temp;
			input.pb(temp);
		}
		countt = 0;

		for(int i=0; i<input.size(); i++){
			if(where.count(input[i])>0){
				++countt;
				it = where.find(input[i]);
				int I=it->second.first, J=it->second.second;
				checked[I][J] = true;
			}
			if(countt >= 4){
				if(check()){
					countt = i+1;
					break;
				}
			}
		}
		printf("BINGO after %d numbers announced\n", countt);
	}
	return 0;
}

bool check(){
	bool done = true;
	//horizontal
	for(int i=0; i<5; i++){
		done = true;
		for(int j=0; j<5; j++){
			if(!checked[i][j]){
				done = false;
				break;
			}
		}
		if(done) return done;
	}
	//vertical
	for(int i=0; i<5; i++){
		done = true;
		for(int j=0; j<5; j++){
			if(!checked[j][i]){
				done = false;
				break;
			}
		}
		if(done) return done;
	}
	if(checked[4][0] && checked[3][1] && checked[2][2] && checked[1][3] && checked[0][4])
		return true;
	if(checked[0][0] && checked[1][1] && checked[2][2] && checked[3][3] && checked[4][4])
		return true;
	return false;
}
