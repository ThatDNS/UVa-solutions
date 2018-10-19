// Problem: 11292 - Dragon of Loowater
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int H, K, temp, expense;
	vector<int> heads;
	vector<int> knights;
	while(cin >> H >> K && (H!=0 && K!=0)){
		//cout << H << " " << K << endl;
		expense=0; heads.clear(); knights.clear();
		for(int i=0; i<H; i++){
			cin >> temp;
			heads.push_back(temp);
		}
		for(int i=0; i<K; i++){
			cin >> temp;
			knights.push_back(temp);
		}
		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());
		int i=0, j=0;
		for(; i<H && j<K;){
			if(heads[i] <= knights[j]){
				expense += knights[j];
				++i; ++j;
			}else{
				++j;
			}
		}
		if(i != H){
			cout << "Loowater is doomed!\n";
		}else{
			cout << expense << endl;
		}
	}
	return 0;
}
