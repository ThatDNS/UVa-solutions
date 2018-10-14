// Problem: 978 - Lemmings Battle!
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	short int N, flag=0;
	cin >> N;
	long long B, SG, SB, temp, warr1, warr2;
	multiset<int, greater <int> > green;
	multiset<int, greater <int> > blue;
	multiset<int>::iterator it1, it2;
	vector<int> tempStor1, tempStor2;
	while(N--){
		if(flag==1) cout << endl;
		if(flag==0) flag=1;
		green.clear(); blue.clear();
		tempStor1.clear(); tempStor2.clear();
		cin >> B >> SG >> SB;
		for(int i=0; i<SG; i++){
			cin >> temp;
			green.insert(temp);
		}
		for(int i=0; i<SB; i++){
			cin >> temp;
			blue.insert(temp);
		}
		while(!green.empty() && !blue.empty()){
			tempStor1.clear(); tempStor2.clear();
			for(int j=0; j<B; j++){
				if(green.empty() || blue.empty())
					continue;
				it1 = green.begin();
				it2 = blue.begin();
				warr1 = *it1;
				warr2 = *it2;
				green.erase(it1);
				blue.erase(it2);
				if(warr1 > warr2){
					temp = warr1 - warr2;
					tempStor1.push_back(temp);
				}else if(warr1 < warr2){
					temp = warr2 - warr1;
					tempStor2.push_back(temp);
				}
			}
			for(int i : tempStor1){
				green.insert(i);
			}
			for(int i : tempStor2){
				blue.insert(i);
			}
		}
		if(green.empty() && blue.empty()){
			cout << "green and blue died" << endl;
		}else if(green.empty() && !blue.empty()){
			cout << "blue wins" << endl;
			for(int i : blue){
				cout << i << endl;
			}
		}else if(!green.empty() && blue.empty()){
			cout << "green wins" << endl;
			for(int i : green){
				cout << i << endl;
			}
		}
	}
	return 0;
}