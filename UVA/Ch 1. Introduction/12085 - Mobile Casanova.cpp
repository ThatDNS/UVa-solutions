// Problem: 12085 - Mobile Casanova
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
#define quick ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

void printDiff(long long a, long long b);

int main(){
	int n, caseNo=0;
	vector<long long> no;
	long long temp, start, count;
	while(cin >> n && n!=0){
		no.clear();
		for(int i=0; i<n; i++){
			cin >> temp;
			no.pb(temp);
		}
		printf("Case %d:\n", ++caseNo);

		start = no[0];
		if(no.size()==1)
			cout << "0" << start << endl;
		count = 0;
		for(int i=1; i<no.size(); i++){
			if(no[i] == start+count+1){
				++count;
			}else{
				if(count == 0){
					cout << "0" << start << endl;
				}else{
					cout << "0" << start << "-";
					printDiff(start, start+count);
					printf("\n");
				}
				if(i == no.size()-1) cout << "0" << no[i] << endl;
				start = no[i];
				count = 0;
			}
		}
		if(count > 0){
			cout << "0" << start << "-";
			printDiff(start, start+count);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

void printDiff(long long a, long long b){
	string sa=to_string(a), sb=to_string(b);
	char ca, cb;
	string change="";
	bool start = false;
	for(int i=0; i<sa.size(); i++){
		ca = sa[i]; cb = sb[i];
		if(ca!=cb || start){
			if(!start) start = true;
			change += cb;
		}
	}
	cout << change;
}

