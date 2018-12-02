// Problem: 10576 - Y2K Accounting Bug
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

vi seq;
int maxProf(int s, int d, int choose);

int main(){
	int s, d;
	while(cin >> s >> d){
		seq.clear();
		int res = maxProf(s, d, -1);
		if(res>0)
			printf("%d\n", res);
		else
			printf("Deficit\n");
	}
	return 0;
}

// 1: s, 2: d
int maxProf(int s, int d, int choose){
	if(choose == 1)
		seq.pb(s);
	else if(choose == 2)
		seq.pb(-1*d);
	if(seq.size() > 4){
		int sum=0;
		for(int i=(int)seq.size()-5; i<(int)seq.size(); i++)
			sum += seq[i];
		if(sum>=0)
			return INT_MIN;
	}
	if(seq.size() == 12){
		int sum=0;
		for(int i=0; i<(int)seq.size(); i++)
			sum += seq[i];
		return sum;
	}
	int prof1 = maxProf(s, d, 1);
	seq.pop_back();
	int prof2 = maxProf(s, d, 2);
	seq.pop_back();
	return max(prof1, prof2);
}

