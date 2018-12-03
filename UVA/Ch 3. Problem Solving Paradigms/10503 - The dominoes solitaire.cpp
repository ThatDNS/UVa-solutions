// Problem: 10503 - The dominoes solitaire
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
bool ifPossible(int A[], int B[]);
int start, endd, n, m;
vi chosen;
map<int, bool> howChosen; //true: as it is; false: inverted
map<int, bool>::iterator it;
set<int> considered;
int main(){
	int left[3], right[3];
	while(cin >> n && n!=0){
		cin >> m;
		int A[m+2], B[m+2];
		cin >> left[0] >> left[1];
		cin >> right[0] >> right[1];
		start = left[1]; endd = right[0];
		for(int i=0; i<m; i++)
			cin >> A[i] >> B[i];
		if(ifPossible(A, B))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

bool ifPossible(int A[], int B[]){
	if(chosen.size() == n){
		int prev = start, curr, next;
		for(int i=0, ind; i<n; i++){
			ind = chosen[i];
			it = howChosen.find(ind);
			if(it->second){
				curr = A[ind];
				next = B[ind];
			}else{
				curr = B[ind];
				next = A[ind];
			}
			if(prev!=curr)
				return false;
			prev = next;
		}
		if(next != endd)
			return false;
		return true;
	}

	bool possible = false;
	int pastInd, pastVal;
	if(chosen.size() == 0){
		pastVal = start;
	}else{
		pastInd = chosen[(int)chosen.size()-1];
		it = howChosen.find(pastInd);
		if(!it->second)
			pastVal = A[pastInd];
		else
			pastVal = B[pastInd];
	}
	for(int i=0; i<m; i++){
		if(A[i] == pastVal && !considered.count(i) && !possible){
			chosen.pb(i);
			considered.insert(i);
			howChosen.insert(pair<int, bool> (i, true));
			possible = possible | ifPossible(A, B);
			int x = chosen[(int)chosen.size()-1];
			considered.erase(i);
			howChosen.erase(x);
			chosen.pop_back();
		}
		if(B[i] == pastVal && !considered.count(i) && !possible){
			chosen.pb(i);
			considered.insert(i);
			howChosen.insert(pair<int, bool> (i, false));
			possible = possible | ifPossible(A, B);
			int x = chosen[(int)chosen.size()-1];
			considered.erase(i);
			howChosen.erase(x);
			chosen.pop_back();
		}
	}
	return possible;
}
