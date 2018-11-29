// 735 - Dart-a-Mania
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

int main(){
	int n, a, b, c, comb, perm;
	set<int> vals; vals.insert(0); vals.insert(50);
	for(int i=1; i<=20; i++){
		vals.insert(i);
		vals.insert(2*i);
		vals.insert(3*i);
	}
	set<int>::iterator valIT1, valIT2, valIT3;
	vi val;
	for(valIT1=vals.begin(); valIT1!=vals.end(); ++valIT1){
		a = *valIT1;
		val.pb(a);
	}
	while(cin >> n && n>0){
		bool arr[62][62][62];
		for(int i=0; i<=60; i++)
			for(int j=0; j<=60; j++)
				for(int k=0; k<=60; k++)
					arr[i][j][k] = false;
		comb=0; perm=0;
		for(int i=0; i<val.size(); i++)
			for(int j=0; j<val.size(); j++)
				for(int k=0; k<val.size(); k++){
					a = val[i]; b = val[j]; c = val[k];
					if(a+b+c == n){
						++perm;
						vi temp; temp.pb(a); temp.pb(b); temp.pb(c);
						sort(temp.begin(), temp.end());
						if(!arr[temp[0]][temp[1]][temp[2]]){
							arr[temp[0]][temp[1]][temp[2]] = true;
							++comb;
						}
					}
				}
		if(perm > 0){
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, comb, n, perm);
		}else{
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
