// Problem: 11236 - Grocery store
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
	long long s, p, x=1000000;
	for(int a=1; 4*a<=2000; a++)
		for(int b=a; a+3*b<=2000; b++)
			for(int c=b; a+b+2*c<=2000; c++){
				p = (long long)a*b*c;
				s = a+b+c;
				if(p <= x) continue;
				if((s*x)%(p-x)) continue;
				int d = (s*x)/(p-x);
				s+=d;
				if(s>2000) continue;
				if(c>d) continue;
				printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", a/100, a%100, b/100, b%100, c/100, c%100, d/100, d%100);
			}
	return 0;
}
