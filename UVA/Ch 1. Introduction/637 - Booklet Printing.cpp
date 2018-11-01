// Problem: 637 - Booklet Printing
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
	short int n, max, where, which;
	vector<ii> orderFront, orderBack;
	while(cin >> n && n!=0){
		orderFront.clear(); orderBack.clear();
		if(n%4==0)
			max = n/4;
		else
			max = n/4 + 1;
		orderFront.assign(max+1, ii(-1, -1));
		orderBack.assign(max+1, ii(-1, -1));
		printf("Printing order for %d pages:\n", n);
		where=1; // 1: 2nd place, 0: 1st place.
		int curr=1;
		for(int i=0; i<max && curr<=n; i++){
			if(where==1 && curr<=n){
				orderFront[i].second = curr;
				where = 0;
				curr++;
			}else if(where==0 && curr<=n){
				orderFront[i].first = curr;
				where = 1;
				curr++;
			}
			if(where==1 && curr<=n){
				orderBack[i].second = curr;
				where = 0;
				curr++;
			}else if(where==0 && curr<=n){
				orderBack[i].first = curr;
				where = 1;
				curr++;
			}
		}
		for(int i=max-1; i>=0 && curr<=n; i--){
			if(where==1 && curr<=n){
				orderBack[i].second = curr;
				where = 0;
				curr++;
			}else if(where==0 && curr<=n){
				orderBack[i].first = curr;
				where = 1;
				curr++;
			}
			if(where==1 && curr<=n){
				orderFront[i].second = curr;
				where = 0;
				curr++;
			}else if(where==0 && curr<=n){
				orderFront[i].first = curr;
				where = 1;
				curr++;
			}
		}
		for(int i=0; i<max; i++){
			ii a = orderFront[i], b = orderBack[i];
			if(a.first!=-1||a.second!=-1){
				printf("Sheet %d, front: ", i+1);
				if(a.first==-1) printf("Blank, ");
				else printf("%d, ", a.first);
				if(a.second==-1) printf("Blank\n");
				else printf("%d\n", a.second);
			}
			if(b.first!=-1||b.second!=-1){
				printf("Sheet %d, back : ", i+1);
				if(b.first==-1) printf("Blank, ");
				else printf("%d, ", b.first);
				if(b.second==-1) printf("Blank\n");
				else printf("%d\n", b.second);
			}
		}
	}
	return 0;
}


