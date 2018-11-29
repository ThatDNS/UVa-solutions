// Problem: 10114 - Loansome Car Buyer
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
#define INF 1e9 // 10^9

int main(){
	int mon, dep, countM;
	double downPay, amt, currVal, owes, monInst;
	while(cin >> mon >> downPay >> amt >> dep && mon>=0){
		currVal = amt+downPay;
		owes = amt; countM = 0;
		double rate[mon+2], temp, currRate;
		for(int i=0; i<=mon; i++) rate[i] = -2;
		for(int i=0, x, prev=0; i<dep; i++){
			cin >> x >> temp;
			rate[x] = temp;
		}
		monInst = amt/mon;
		currRate = rate[0];
		currVal = (1-currRate)*currVal;
		while(currVal <= owes){
			++countM;
			if(countM <= mon && rate[countM] != -2)
				currRate = rate[countM];
			if(countM <= mon)
				owes -= monInst;
			currVal = (1-currRate)*currVal;
		}
		if(countM == 1)
			printf("%d month\n", countM);
		else
			printf("%d months\n", countM);
	}
	return 0;
}
