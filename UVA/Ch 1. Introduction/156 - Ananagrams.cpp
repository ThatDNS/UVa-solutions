// Problem: 156 - Ananagrams
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
bool check(string a, string b);
int main(){
	string s, s1, s2;
	vector<string> dict;
	set<string> ananas;
	while(cin >> s && s!="#"){
		dict.pb(s);
	}
	bool notFound;
	for(int i=0; i<(int)dict.size(); i++){
		notFound = true;
		s1 = dict[i];
		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		if(s1.length() > 1){
			for(int j=0; j<(int)dict.size(); j++){
				if(i==j) continue;
			 	s2 = dict[j];
			 	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
				if(check(s1, s2)) notFound = false;
			}
		}
		if(notFound){
			ananas.insert(dict[i]);
		}
	}
	for(auto it = ananas.begin(); it!= ananas.end(); it++){
		cout << *it << endl;
	}
	return 0;
}

bool check(string a, string b){
	char c1, c2;
	bool found;
	if(a.length() != b.length())
		return false;
	for(int i=0; i<a.length(); i++){
		c1 = a[i];
		found = false;
		for(int j=0; j<b.length(); j++){
			c2 = b[j];
			if(c1 == c2){
				found = true;
				b[j] = '#';
				break;
			}
		}
		if(!found) return false;
	}
	return true;
}
