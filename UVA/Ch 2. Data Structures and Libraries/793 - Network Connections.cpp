// Problem: 793 - Network Connections
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> p; //parent
vector<int> r; //rank
int findSet(int i);
bool isSameSet(int i, int j);
void unionSet(int i, int j);

int main(){
	int t, flag=0, same=0, notSame=0;
	unsigned int n, a, b;
	char c;
	string s;
	cin >> t;
	while(t--){
		same=0; notSame=0;
		if(flag==1)
			n = stoi(s);
		if(flag==0){
			cin >> n;
			flag=1;
		}
		p.assign(n+2, 0);
		r.assign(n+2, 0);
		for(int i=0; i<=n; i++){
			p[i] = i;
		}
		while(cin >> s && (s=="c"||s=="q")){
			cin >> a >> b;
			if(s=="c"){
				unionSet(a, b);
			}else if(s=="q"){
				if(isSameSet(a, b))
					++same;
				else
					++notSame;
			}
		}
		if(t==0)
			printf("%d,%d\n", same, notSame);
		else
			printf("%d,%d\n\n", same, notSame);
	}
	return 0;
}

int findSet(int i){
	if(p[i]==i){
		return i;
	}else{
		p[i] = findSet(p[i]);
		return p[i];
	}
}

bool isSameSet(int i, int j){
	return findSet(i)==findSet(j);
}

void unionSet(int i, int j){
	if(!isSameSet(i, j)){
		int x = findSet(i), y = findSet(j);
		if(r[x] > r[y]){
			p[y] = x;
		}else{
			p[x] = y;
			if(r[x]==r[y])
				r[y]++;
		}
	}
}

