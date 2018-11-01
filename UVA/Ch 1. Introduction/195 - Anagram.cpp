// Problem: 195 - Anagram
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
void permute(string s);
bool Compare(char a, char b);
int main(){
	int n;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		permute(s);
	}
	return 0;
}

void permute(string s){
	sort(s.begin(), s.end(), Compare);
	cout << s << endl;
	while(next_permutation(s.begin(), s.end(), Compare)){
		cout << s << endl;
	}
}

bool Compare(char a, char b){
	if(tolower(a) == tolower(b))
		return a<b;
	return tolower(a)<tolower(b);
}
