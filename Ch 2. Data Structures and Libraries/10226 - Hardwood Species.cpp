// Problem: 10226 - Hardwood Species
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int cases, count=0;
	string tree, extra;
	cin >> cases;
	while(cases--){
		map<string, int> mapT;
		getline(cin, extra);
		while(getline(cin, tree)){
			if(tree == ""){
				map<string, int>::iterator it;
				for(it = mapT.begin(); it != mapT.end(); ++it){
					cout << it->first << " " << fixed <<setprecision(4) << it->second*100.0/count << endl;
				}
				if(mapT.size()!=0) cout << endl;
				mapT.clear();
				count = 0;
				continue;
			}
			++count;
			if(!mapT.count(tree)){
				mapT.insert(pair <string, int> (tree, 1));
			}else{
				auto find = mapT.find(tree);
				find->second += 1;
			}
		}
		map<string, int>::iterator it;
		for(it = mapT.begin(); it != mapT.end(); ++it){
			cout << it->first << " " << fixed <<setprecision(4) << it->second*100.0/count << endl;
		}
	}
	return 0;
}
