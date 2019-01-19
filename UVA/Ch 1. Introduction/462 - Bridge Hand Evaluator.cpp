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


vector<string> cards;
vector<vector<string> > suits;
bool isStop[5];

int main(){
	string s, temp;
	int score=0;
	char sep = ' ';
	vector<string> sp, ht, di, cl;
	while(getline(cin, s)){
		score=0; suits.clear();
		isStop[0]=false; isStop[1]=false; isStop[2]=false; isStop[3]=false;
		cards.clear(); sp.clear(); ht.clear(); di.clear(); cl.clear();
		stringstream ss(s); sep = ' ';
		while(getline(ss, temp, sep)){
			cards.pb(temp);
		}
		suits.pb(sp); suits.pb(ht); suits.pb(di); suits.pb(cl);
		for(int i=0; i<cards.size(); i++){
			temp = cards[i];
			sep = temp[0];
			//Rule 1
			if(sep == 'A')
				score += 4;
			else if(sep == 'K')
				score += 3;
			else if(sep == 'Q')
				score += 2;
			else if(sep == 'J')
				score += 1;
			//separate
			sep = temp[1];
			if(sep == 'S')
				suits[0].pb(temp);
			else if(sep == 'H')
				suits[1].pb(temp);
			else if(sep == 'D')
				suits[2].pb(temp);
			else if(sep == 'C')
				suits[3].pb(temp);
		}

		//Rule 2,3,4
		for(int j=0; j<suits.size(); j++){
			for(int i=0; i<suits[j].size(); i++){
				temp = suits[j][i];
				sep = temp[0];
				if(i==0 && sep=='K' && suits[j].size()==1)
					score -= 1;
				else if(sep=='Q' && (suits[j].size()==1 || suits[j].size()==2))
					score -= 1;
				else if(sep=='J' && (suits[j].size()==1 || suits[j].size()==2 || suits[j].size()==3))
					score -= 1;
			}
		}
		//checking if stopped
		for(int j=0; j<suits.size(); j++){
			for(int i=0; i<suits[j].size(); i++){
				temp = suits[j][i];
				sep = temp[0];
				if(sep=='A'){
					isStop[j] = true; continue;
				}else if(sep=='K' && suits[j].size()>=2){
					isStop[j] = true; continue;
				}else if(sep=='Q' && suits[j].size()>=3){
					isStop[j] = true; continue;
				}
			}
		}
		if(score>=16 && isStop[0] && isStop[1] && isStop[2] && isStop[3]){
			printf("BID NO-TRUMP\n");
			continue;
		}
		//Rule 5,6,7
		int most=INT_MIN;
		char bidSuit;
		for(int j=suits.size()-1, no; j>=0; j--){
			if(suits[j].size() == 2)
				++score;
			else if(suits[j].size() == 1)
				score += 2;
			else if(suits[j].size() == 0)
				score += 2;
			no = suits[j].size();
			if(no >= most){
				most = no;
				if(j==0) bidSuit = 'S';
				else if(j==1) bidSuit = 'H';
				else if(j==2) bidSuit = 'D';
				else if(j==3) bidSuit = 'C';
			}
		}
		if(score >= 14){
			printf("BID %c\n", bidSuit);
		}else{
			printf("PASS\n");
		}
	}
	return 0;
}
