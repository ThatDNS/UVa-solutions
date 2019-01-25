// Problem: 11926 - Multitasking
/**
 *	Author: DNS404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;
#define EPS 1e-9 // 10^-9
#define pb push_back
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

#define N 1000001

int main(){
	int n, m, temp1, temp2, temp3, start, end, recc;
	bitset<N> schedule;
	vi stI, endI, st, ed, rec;
	while(cin >> n >> m){
		if(n==0 && m==0)
			break;
		stI.clear(); endI.clear(); st.clear(); ed.clear(); rec.clear();
		schedule.reset();
		//input
		for(int i=0; i<n; i++){
			cin >> temp1 >> temp2;
			stI.pb(temp1); endI.pb(temp2);
		}
		for(int i=0; i<m; i++){
			cin >> temp1 >> temp2 >> temp3;
			st.pb(temp1); ed.pb(temp2); rec.pb(temp3);
		}
		//check
		bool conflict = false;
		for(int i=0; i<n && !conflict; i++){
			start = stI[i]; end = endI[i];
			for(int t = start; t<end && !conflict; t++){
				if(schedule.test(t))
					conflict = true;
				else
					schedule.set(t);
			}
		}
		for(int i=0; i<m && !conflict; i++){
			start = st[i]; end = ed[i]; recc = rec[i];
			while(start < 1000000 && !conflict){
				for(int t=start; t<end && !conflict; t++){
					if(schedule.test(t))
						conflict = true;
					else
						schedule.set(t);
				}
				start += recc;
				end = min(end+recc, 1000000); //if task starts but doesn't end
			}
		}
		//output
		if(conflict)
			printf("CONFLICT\n");
		else
			printf("NO CONFLICT\n");
	}
	return 0;
}
