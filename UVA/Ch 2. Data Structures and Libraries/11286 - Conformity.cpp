// Problem: 11286 - Conformity
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, max, count=0;
	vector<int> courses;
	while(cin >> a && a != 0){
		map<vector<int> , int> mapC;
		max = INT_MIN;
		count = 0;
		for(int i=0; i<a; i++){
			courses.clear();
			for(int j=0; j<5; j++){
				cin >> b;
				courses.push_back(b);
			}
			sort(courses.begin(), courses.end());
			if(!mapC.count(courses)){
				mapC.insert(pair <vector<int>, int> (courses, 1));
			}else{
				auto find = mapC.find(courses);
				find->second += 1;
			}
		}
		map<vector<int> , int>::iterator it;
		for(it = mapC.begin(); it != mapC.end(); ++it){
			if(it->second > max){
				max = it->second;
				count = 0;
				++count;
			}else if(it->second == max){
				++count;
			}
		}
		cout << count*max << endl;
	}
	return 0;
}