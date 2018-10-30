// Problem: 574 - Sum It Up
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define EPS 1e-9
#define pb push_back

short int t, n, temp;
vi no, vec;
vb visited;
void findSums(int sum, int pos);
set<vi, greater <vi> > final;

int main(){
	while(cin >> t){
		cin >> n;
		if(n==0)
			break;
		no.clear(); final.clear();
		visited.assign(17, false);
		for(int i=0; i<n; i++){
			cin >> temp; no.pb(temp);
		}
		printf("Sums of %d:\n", t);
		findSums(0, 0);
		for(auto it=final.begin(); it!=final.end(); it++){
			vi x = (*it);
			for(int i=0; i<x.size(); i++)
				printf((i!=x.size()-1)?"%d+":"%d\n", x[i]);
		}
		if(final.begin()==final.end())
			cout << "NONE\n";
	}
	return 0;
}

void findSums(int sum, int pos){
	if(sum > t) return;
	if(sum == t){
		final.insert(vec);
		return;
	}
	for(int j=pos; j<no.size(); j++){
		int i = no[j];
		if(!visited[j]){
			if(vec.size()>=1){
				if(vec[vec.size()-1] < i)
					continue;
			}
			visited[j] = true;
			vec.pb(i);
			findSums(sum+i, j);
			vec.pop_back();
			visited[j] = false;
		}
	}
}
