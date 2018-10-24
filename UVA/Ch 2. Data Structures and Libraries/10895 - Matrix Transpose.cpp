// Problem: 10895 - Matrix Transpose
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int m, n, r, temp;
	vector<int> pos, el;
	while(cin >> m >> n){
		int mat[m+2][n+2];
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++)
				mat[i][j] = 0;
		}
		for(int x=1; x<=m; x++){
			cin >> r;
			pos.clear();
			if(r!=0){
				for(int y=0; y<r; y++){
					cin >> temp;
					pos.pb(temp);
				}
				for(int y=0; y<r; y++){
					cin >> temp;
					mat[x][pos[y]] = temp;
				}
			}
		}
		cout << n << " " << m << endl;
		for(int i=1; i<=n; i++){
			el.clear(); pos.clear();
			for(int j=1; j<=m; j++){
				if(mat[j][i] != 0){
					pos.pb(j);
					el.pb(mat[j][i]);
				}
			}
			if(pos.size()!=0)
				cout << pos.size() << " ";
			else
				cout << pos.size() << "\n";
			for(int j=0; j<pos.size(); j++){
				if(j!=pos.size()-1)
					cout << pos[j] << " ";
				else
					cout << pos[j] << "\n";
			}
			if(el.size()==0) cout << "\n";
			for(int j=0; j<el.size(); j++){
				if(j!=el.size()-1)
					cout << el[j] << " ";
				else
					cout << el[j] << "\n";
			}
		}
	}
	return 0;
}
