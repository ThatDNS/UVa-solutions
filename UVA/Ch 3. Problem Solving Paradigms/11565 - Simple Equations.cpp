// Problem: 11565 - Simple Equations
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, a, b, c;
	bool found=false;
	cin >> n;
	while(n--){
		cin >> a >> b >> c;
		found=false;
		for(int x=-22; x<=22 && !found; x++){
			for(int y=-100; y<=100 && !found; y++){
				for(int z=-100; z<=100 && !found; z++){
					if(x!=y && y!=z && z!=x && (x+y+z)==a && (x*y)*z==b && (x*x+y*y+z*z)==c){
						cout << x << " " << y << " " << z << endl;
						found=true;
					}
				}
			}
		}
		if(!found){
			cout << "No solution.\n";
		}
	}
	return 0;
}
