// Problem: 787 - Maximum Sub-sequence Product
/**
 *	Author: DNS-404
 **/

/* Concept:
Example: -5, -2, 2, -30
Do all multiplications and store them in a 2d table.
Don't do multiplications in O(n^2). Just multiply column number to the
value in previous cell.

    -5   -2  2  -30
-5 | x | 10| 20|-600|
-2 |   | x |-4 | 120|
 2 |   |   | x | -60|
-30|   |   |   |  x |

Maximum value is 120. So, 120 is answer.
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define EPS 1e-9 // 10^-9
#define pb push_back
#define INF 1e9 // 10^9

int main(){
	vi nos;
	int no;
	while(cin >> no){
		nos.clear();
		nos.pb(no);
		while(cin >> no && no != -999999)
			nos.pb(no);
		long long arr[(int)nos.size()+2][(int)nos.size()+2], ans=INT_MIN;
		for(int i=0; i<(int)nos.size(); i++){
			arr[i][i] = nos[i];
			ans = max(ans, arr[i][i]);
		}
		for(int i=0; i<(int)nos.size(); i++){
			for(int j=i+1; j<(int)nos.size(); j++){
				arr[i][j] = arr[i][j-1] * nos[j];
				ans = max(ans, arr[i][j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
