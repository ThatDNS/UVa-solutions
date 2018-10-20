// Problem: 10341 - Solve It
// This is done using bisection method. Newton's method is even faster. Google it.
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
#define EPS 1e-7
using namespace std;
short int p, q, r, s, t, u;
double f(double x);
double bisection();
int main(){
	while(cin>>p>>q>>r>>s>>t>>u){
		if(f(0)*f(1)>0){
			cout << "No solution\n";
			continue;
		}
		printf("%.4lf\n", bisection());
	}
	return 0;
}

double bisection(){
	double low = 0, high = 1;
	while(low + EPS < high){
		double x = (low+high)/2;
		if(f(x)*f(high) <= 0){
			low = x;
		}else{
			high = x;
		}
	}
	return (low+high)/2;
}

double f(double x){
	double ans = p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
	return ans;
}