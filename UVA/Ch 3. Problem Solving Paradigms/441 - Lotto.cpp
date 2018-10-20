// Problem: 441 - Lotto
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	short int k, flag=0;
	while(cin >> k && k!=0){
		if(flag==1) cout << endl;
		if(flag==0) flag=1;
		int arr[k+2];
		for(int i=0; i<k; i++)
			cin >> arr[i];
		for(int a=0; a<k-5; a++){
			for(int b=a+1; b<k-4; b++){
				for(int c=b+1; c<k-3; c++){
					for(int d=c+1; d<k-2; d++){
						for(int e=d+1; e<k-1; e++){
							for(int f=e+1; f<k; f++){
								printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
