// Problem: 10507 - Waking up brain
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<vector<char> > adjList;
vector<bool> isAwake;
map<char, int> vert;
map<char, int>::iterator it;
vector<char> con1, con2;
int ii;
int main(){
	short int n; // #slept areas
	int m; // #connections;
	string awake, con;
	char a, b;
	while(cin >> n){
		adjList.clear(); vert.clear(); ii=0;
		con1.clear(); con2.clear(); isAwake.clear();
		adjList.assign(n, vector<char>());
		isAwake.assign(n, false);
		cin >> m;
		cin >> awake;
		for(int i=0; i<m; i++){
			cin >> con;
			a = con[0]; b = con[1];
			if(vert.count(a)==0)
				vert.insert(pair<char, int> (a, ii++));
			if(vert.count(b)==0)
				vert.insert(pair<char, int> (b, ii++));
			con1.pb(a);
			con2.pb(b);
		}
		for(int i=0; i<3; i++){
			a = awake[i];
			if(vert.count(a)){
				it = vert.find(a);
				isAwake[it->second] = true;
			}
		}
		for(int i=0; i<con1.size(); i++){
			it = vert.find(con1[i]);
			adjList[it->second].pb(con2[i]);
			it = vert.find(con2[i]);
			adjList[it->second].pb(con1[i]);
		}
		int count=0, totalAwake=3, years=0;
		bool found=false, didntWake=false;
		vector<int> toBeAwaken;
		while(totalAwake<n){
			toBeAwaken.clear();
			found=false;
			for(int i=0; i<n; i++){
				if(isAwake[i])
					continue;
				for(char j: adjList[i]){
					it = vert.find(j);
					if(isAwake[it->second])
						++count;
				}
				if(count >= 3){
					toBeAwaken.pb(i);
					++totalAwake;
					found=true;
				}
				count=0;
			}
			if(!found){
				cout << "THIS BRAIN NEVER WAKES UP\n";
				didntWake=true;
				break;
			}
			for(int i=0; i<toBeAwaken.size(); i++){
				isAwake[toBeAwaken[i]] = true;
			}
			++years;
		}
		if(!didntWake) printf("WAKE UP IN, %d, YEARS\n", years);
	}
	return 0;
}

