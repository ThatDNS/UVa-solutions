// Problem: 454 - Anagrams
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

bool isAnagram(string a, string b);
bool isFirst(string s1, string s2);

int main(){
	int tests, flag=0, n1, n2;
	string s,s1,s2;
	cin >> tests;
	getline(cin, s);cin.ignore();
	while(tests--){
		vector<string> ss;
		vector<pair<string, string> > vec;
		if(flag==1) cout << "\n";
		if(flag==0) flag=1;
		while(getline(cin, s) && s!=""){
			ss.pb(s);
		}
		for(int i=0; i<(int)ss.size(); i++){
			for(int j=i+1; j<(int)ss.size(); j++){
				s1 = ss[i]; s2 = ss[j];
				if(isAnagram(s1, s2)){
					if(isFirst(s1, s2))
						vec.pb(make_pair(s1, s2));
					else
						vec.pb(make_pair(s2, s1));
				}
			}
		}
		sort(vec.begin(), vec.end());
		for(int i=0; i<vec.size(); i++){
			if(isFirst(vec[i].first, vec[i].second)) // final check :P
				cout << vec[i].first << " = " << vec[i].second << endl;
			else
				cout << vec[i].second << " = " << vec[i].first << endl;
		}
	}
}

bool isFirst(string s1, string s2){
	for(int i=0; i<s1.length(); i++){
		if((int)s1[i] < (int)s2[i]) return true;
		else if((int)s1[i] > (int)s2[i]) return false;
	}
	return true;
}

bool isAnagram(string a, string b){
	std::string::iterator end_pos = std::remove(a.begin(), a.end(), ' ');
	a.erase(end_pos, a.end());
	end_pos = std::remove(b.begin(), b.end(), ' ');
	b.erase(end_pos, b.end());
	if(a.length() != b.length())
		return false;
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	if(a == b)
		return true;
	return false;
}
