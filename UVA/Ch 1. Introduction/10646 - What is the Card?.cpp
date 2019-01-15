// Problem: 10646 - What is the Card?
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
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

int main(){
	int n, cases=0;
	vector<string> deck, hand;
	string s;
	char c;
	cin >> n;
	int x,y, ind;
	while(n--){
		deck.clear(); hand.clear(); x=0; y=0;
		for(int i=0; i<52; i++){
			cin >> s;
			deck.pb(s);
		}
		for(int i=26; i<52; i++){
			s = deck[i];
			hand.pb(s);
		}
		ind = (int)deck.size()-1;
		for(int i=0; i<26; i++)
			--ind;

		for(int i=0; i<3; i++){
			s = deck[ind-1];
			c = s[0];
			if((int)c>=50 && (int)c<=57){
				x = (int)c - 48;
			}else{
				x = 10;
			}
			y+=x;
			--ind;
			for(int k=0; k<(10-x); k++){
				--ind;
			}
		}
		bool temp;
		for(int i=0; i<y; i++){
			if(i <= ind){
				x = i;
				temp = false;
			}else{
				x = i-ind-1;
				temp = true;
			}
		}

		printf("Case %d: ", ++cases);
		if(temp)
			cout << hand[x] << endl;
		else
			cout << deck[x] << endl;
	}
	return 0;
}

