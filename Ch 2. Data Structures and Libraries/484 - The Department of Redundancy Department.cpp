// Problem: 484 - The Department of Redundancy Department
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, x;
	map<int, int> vals;
	vector<int> order;
	while(cin >> a){
		auto find = vals.find(a);
		if(!vals.count(a)){
			order.push_back(a);
			vals.insert(pair <int, int> (a, 1));
		}
		find->second += 1;
	}
	for(int i=0; i<order.size(); i++){
		x = order[i];
		auto find = vals.find(x);
		cout << find->first << " " << find->second << endl;
	}
	return 0;
}