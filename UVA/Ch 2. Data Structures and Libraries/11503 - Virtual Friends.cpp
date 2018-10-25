// Problem: 11503 - Virtual Friends
// I wrote really big code for this one. lol. This is complete implementation of Disjoint sets btw.
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> p; //parent
vector<int> r; //rank
vector<int> SS; //size of tree
int findSet(int i);
bool isSameSet(int i, int j);
void unionSet(int i, int j);

int main(){
	int t, f, index=0;
	cin >> t;
	string s, f1, f2;
	vector<int> frnd1;
	vector<int> frnd2;
	map<string, int> frndIndex;
	map<string, int>::iterator it;
	while(t--){
		frnd1.clear(); frnd2.clear(); frndIndex.clear();
		index = 0; p.clear(); r.clear();
		cin >> f;
		getline(cin , s);
		for(int i=0; i<f; i++){
			getline(cin , s);
			f1 = s.substr(0, s.find(" "));
			f2 = s.substr(s.find(" ")+1, s.length()-s.find(" "));
			if(!frndIndex.count(f1))
				frndIndex.insert(pair<string, int> (f1, index++));
			if(!frndIndex.count(f2))
				frndIndex.insert(pair<string, int> (f2, index++));
			it = frndIndex.find(f1);
			frnd1.pb(it->second);
			it = frndIndex.find(f2);
			frnd2.pb(it->second);
		}
		r.assign(2*frnd1.size(), 0);
		p.assign(2*frnd1.size(), 0);
		SS.assign(2*frnd1.size(), 1);
		for(int i=0; i<frnd1.size(); i++){
			r[frnd1[i]] = 0; r[frnd2[i]] = 0;
			p[frnd1[i]] = 0; p[frnd2[i]] = 0;
			SS[frnd1[i]] = 1; SS[frnd2[i]] = 1;
		}
		for(int i=0; i<frnd1.size(); i++){
			p[frnd1[i]] = frnd1[i];
			p[frnd2[i]] = frnd2[i];
		}
		for(int i=0; i<frnd1.size(); i++){
			unionSet(frnd1[i], frnd2[i]);
			int a = findSet(frnd1[i]);
			cout << SS[a] << endl;
		}
	}
	return 0;
}

int findSet(int i){
	if(p[i]==i){
		return i;
	}else{
		p[i] = findSet(p[i]);
		return p[i];
	}
}

bool isSameSet(int i, int j){
	return findSet(i)==findSet(j);
}

void unionSet(int i, int j){
	if(!isSameSet(i, j)){
		int x = findSet(i), y = findSet(j);
		if(r[x] > r[y]){
			p[y] = x;
			SS[x] += SS[y];
		}else{
			p[x] = y;
			SS[y] += SS[x];
			if(r[x]==r[y])
				r[y]++;
		}
	}
}

