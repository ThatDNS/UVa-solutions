// Problem: 10102 - The path in the colored field
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int m, ans, dist;
	vector<int> oneX, oneY, threeX, threeY, final;
	while(cin >> m){
		oneX.clear(); oneY.clear(); threeX.clear(); threeY.clear(); final.clear();
		string s[m+2]; char c;
		for(int i=0; i<m; i++){
			cin >> s[i];
		}
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++){
				c = s[i][j];
				if(c == '1'){
					oneX.push_back(i);
					oneY.push_back(j);
				}else if(c == '3'){
					threeX.push_back(i);
					threeY.push_back(j);
				}
			}
		}
		for(int i=0; i<oneX.size(); i++){
			ans = INT_MAX;
			for(int j=0; j<threeX.size(); j++){
				dist = abs(oneX[i]-threeX[j])+abs(oneY[i]-threeY[j]);
				if(dist < ans)
					ans = dist;
			}
			final.push_back(ans);
		}
		sort(final.begin(), final.end());
		cout << final[final.size()-1] << endl;

	}
	return 0;
}