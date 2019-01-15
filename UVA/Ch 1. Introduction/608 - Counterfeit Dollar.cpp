// Problem: 608 - Counterfeit Dollar
// Concept: The solution is huge :P Sorry for that. It's just basic brute force.
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

int main(){
	int n, wt; // wt:0 - light, 1 - heavy
	vector<string> left, right, pos;
	string a, b, c;
	char cc, cc1, res, curr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
	cin >> n;
	while(n--){
		left.clear(); right.clear(); pos.clear();
		for(int i=0; i<3; i++){
			cin >> a >> b >> c;
			left.pb(a); right.pb(b); pos.pb(c);
		}

		int scoreL=0, scoreR=0;
		bool fst, scnd, trd;
		for(int i=0; i<12; i++){
			cc = curr[i];

			//LIGHT
			fst=false; scnd=false; trd=false;
			for(int j=0; j<3; j++){
				scoreL=0; scoreR=0;
				//left
				for(int k=0; k<left[j].size(); k++){
					cc1 = left[j][k];
					if(cc1 == cc){
						scoreL += 1;
					}else{
						scoreL += 2;
					}
				}
				//right
				for(int k=0; k<right[j].size(); k++){
					cc1 = right[j][k];
					if(cc1 == cc){
						scoreR += 1;
					}else{
						scoreR += 2;
					}
				}
				if(scoreL == scoreR && pos[j] == "even"){
					if(j==0) fst = true;
					else if(j==1) scnd = true;
					else if(j==2) trd = true;
				}else if(scoreL < scoreR && pos[j] == "down"){
					if(j==0) fst = true;
					else if(j==1) scnd = true;
					else if(j==2) trd = true;
				}else if(scoreL > scoreR && pos[j] == "up"){
					if(j==0) fst = true;
					else if(j==1) scnd = true;
					else if(j==2) trd = true;
					continue;
				}else{
					if(j==0) fst = false;
					else if(j==1) scnd = false;
					else if(j==2) trd = false;

				}
			}

			// All true
			if(fst && scnd && trd){
				res = cc;
				wt = 0; //light
				break;
			}

			//HEAVY
			fst=false; scnd=false; trd=false;
			for(int j=0; j<3; j++){
				scoreL=0; scoreR=0;
				//left
				for(int k=0; k<left[j].size(); k++){
					cc1 = left[j][k];
					if(cc1 == cc){
						scoreL += 3;
					}else{
						scoreL += 2;
					}
				}
				//right
				for(int k=0; k<right[j].size(); k++){
					cc1 = right[j][k];
					if(cc1 == cc){
						scoreR += 3;
					}else{
						scoreR += 2;
					}
				}
				if(scoreL == scoreR && pos[j] == "even"){
					if(j==0) fst = true;
					else if(j==1) scnd = true;
					else if(j==2) trd = true;
				}else if(scoreL < scoreR && pos[j] == "down"){
					if(j==0) fst = true;
					else if(j==1) scnd = true;
					else if(j==2) trd = true;
				}else if(scoreL > scoreR && pos[j] == "up"){
					if(j==0) fst = true;
					else if(j==1) scnd = true;
					else if(j==2) trd = true;
					continue;
				}else{
					if(j==0) fst = false;
					else if(j==1) scnd = false;
					else if(j==2) trd = false;

				}
			}
			// All true
			if(fst && scnd && trd){
				res = cc;
				wt = 1; //heavy
				break;
			}
		}

		if(wt==0){
			cout << res << " is the counterfeit coin and it is light.\n";
		}else if(wt==1){
			cout << res << " is the counterfeit coin and it is heavy.\n";
		}
		
	}
	return 0;
}
