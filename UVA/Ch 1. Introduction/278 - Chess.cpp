// Problem: 278 - Chess
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define EPS 1e-9 // 10^-9
#define pb push_back
#define INF 1e9 // 10^9xs
int gcd(int a, int b);
int main(){
	int prob, m, n;
	char c;
	cin >> prob;
	while(prob--){
		cin >> c >> m >> n;
		if(c == 'r'){
			cout << min(m, n) << endl;
		}else if(c == 'K'){
			int in_a_row = (n%2==0)?n/2:n/2+1;
			int cols = (m%2==0)?m/2:m/2+1;
			cout << cols*in_a_row << endl;
		}else if(c == 'Q'){
			cout << min(m, n) << endl;
		}else if(c == 'k'){
			int row1 = (m%2==0)?m/2:m/2+1;
			int row2 = (m%2==0)?m/2:m/2;
			int total=0;
			if(n%2==0)
				total = (row1+row2) * (n/2);
			else{
				total = (row1+row2) * ((n-1)/2);
				total += row1;
			}
			cout << total << endl;
		}

	}
	return 0;
}
