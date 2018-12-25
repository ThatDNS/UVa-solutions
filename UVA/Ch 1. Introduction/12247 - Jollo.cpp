// Problem: 12247 - Jollo
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

void InitCheck(int chosen1, int chosen2, int cx, int cy);
void CheckNow(int tempWins, int tempLost);
void FinalCheck(int n);

short int a, b, c, x, y;
int wins, lost;
int taken[54], netWins=0;
bool found;

int main(){
	while(cin>>a>>b>>c>>x>>y && (a!=0||b!=0||c!=0||x!=0||y!=0)){
		memset(taken, 0, sizeof(taken));
		taken[a]=1; taken[b]=1; taken[c]=1; taken[x]=1; taken[y]=1;
		wins=0; lost=0;
		// All checks
		InitCheck(a, b, 0, 0);
		if((lost == 1 && wins == 1) || wins == 2) InitCheck(a, c, 0, 0);
		if((lost == 1 && wins == 1) || wins == 2) InitCheck(b, a, 0, 0);
		if((lost == 1 && wins == 1) || wins == 2) InitCheck(b, c, 0, 0);
		if((lost == 1 && wins == 1) || wins == 2) InitCheck(c, a, 0, 0);
		if((lost == 1 && wins == 1) || wins == 2) InitCheck(c, b, 0, 0);
		if(lost == 2){
			printf("-1\n");
			continue;
		}else if(wins == 2){
			int n=1;
			while(taken[n]==1)
				++n;
			printf("%d\n", n);
			continue;
		}
		int n=1;
		found = false;
		while(!found){
			if(taken[n] != 1) FinalCheck(n);
			taken[n] = 1;
			++n;
		}
		--n;
		if(n>52)
			printf("-1\n");
		else
			printf("%d\n", n);
	}
	return 0;
}

void InitCheck(int chosen1, int chosen2, int cx, int cy){
	int tempWins=0, tempLost=0;
	if(chosen1 < x)
		++tempWins;
	else
		++tempLost;
	if(chosen2 < y)
		++tempWins;
	else
		++tempLost;
	if(cy!=0){
		if(cx < cy)
			++tempWins;
		else
			++tempLost;
		if(tempWins >= 2){
			++netWins;
			return;
		}
	}else{
		CheckNow(tempWins, tempLost);
	}
}

void FinalCheck(int n){
	netWins=0;
	if(!found) InitCheck(a, b, c, n);
	if(!found) InitCheck(a, c, b, n);
	if(!found) InitCheck(b, a, c, n);
	if(!found) InitCheck(b, c, a, n);
	if(!found) InitCheck(c, a, b, n);
	if(!found) InitCheck(c, b, a, n);
	if(netWins == 6)
		found = true;
}

void CheckNow(int tempWins, int tempLost){
	if(tempLost == 2){
		lost = 2; wins = 0;
	}else if(tempLost == 1 && tempWins == 1){
		lost = 1; wins = 1;
	}else if(tempWins == 2 && (lost!=1 || wins!=1)){
		lost = 0; wins = 2;
	}
	return;
}
