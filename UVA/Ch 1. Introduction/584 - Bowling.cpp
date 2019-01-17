// Problem: 584 - Bowling
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

int what(string s);

int main(){
	string s, temp;
	char sep=' ';
	vector<string> sc;
	int score, count, grp, many=0;
	bool lastStrike, lastSpare;
	while(getline(cin, s)){
		if(s=="Game Over")
			break;
		sc.clear(); score=0; count=0; grp=0;
		many=0;
		lastStrike=false; lastSpare=false;
		stringstream ss(s);
		while(getline(ss, temp, sep)){
			++count;
			sc.pb(temp);
			if(temp == "X" || count == 2){
				grp++;
				count = 0;
				if(grp == 10){
					if(temp == "X")
						lastStrike = true;
					else if(temp == "/")
						lastSpare = true;
				}
				if(grp > 10 && temp == "X")
					many++;
			}
		}

		for(int i=sc.size()-1; i>=0; i--){
			temp = sc[i];
			if(temp == "X"){
				score += 10;
				if(!lastStrike && i<sc.size()-2){
					temp = sc[i+2];
					if(temp == "/"){
						score += 10;
						continue;
					}else if(temp == "X"){
						score += 10;
					}else{
						score += what(temp);
					}
				}
				if(!lastStrike && i<sc.size()-1){
					temp = sc[i+1];
					if(temp == "X")
						score += 10;
					else
						score += what(temp);
				}
				if(lastStrike && many == 0){
					lastStrike = false;
				}else{
					--many;
				}
			}else if(temp == "/"){
				score += 10;
				if(!lastSpare && i<sc.size()-1){
					temp = sc[i+1];
					if(temp == "X"){
						score += 10;
					}else{
						score += what(temp);
					}
				}
				--i;
				if(lastSpare){
					lastSpare = false;
				}
			}else{
				score += what(temp);
			}
		}

		cout << score << endl;
	}
	return 0;
}

int what(string s){
	if(s=="1")
		return 1;
	else if(s=="2")
		return 2;
	else if(s=="3")
		return 3;
	else if(s=="4")
		return 4;
	else if(s=="5")
		return 5;
	else if(s=="6")
		return 6;
	else if(s=="7")
		return 7;
	else if(s=="8")
		return 8;
	else if(s=="9")
		return 9;
	return 0;
}
