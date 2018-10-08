// Problem: 11995 - I Can Guess the Data Structure!
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, a, b, count, flagS=0, flagQ=0, flagPQ=0;
	bool isStack, isQueue, isPrioQueue;
	while(cin >> n){
		stack<int> S;
		queue<int> q;
		priority_queue<int> pq;
		count=0; flagS=0; flagQ=0; flagPQ=0;
		int in=0, out=0;
		isStack=false; isQueue=false; isPrioQueue=false;
		for(int i=0; i<n; i++){
			cin >> a >> b;
			if(a == 1){
				++in;
				S.push(b);
				q.push(b);
				pq.push(b);
			}else if(a == 2){
				++out;
				if(!S.empty()){
					if(flagS==0){isStack=true; flagS=1;}
					if(S.top() != b && isStack){
						isStack = false;
					}else if(S.top() == b && isStack){
						S.pop();
					}
				}
				if(!q.empty()){
					if(flagQ==0){isQueue=true; flagQ=1;}
					if(q.front() != b && isQueue){
						isQueue = false;
					}else if(q.front() == b && isQueue){
						q.pop();
					}
				}
				if(!pq.empty()){
					if(flagPQ==0){isPrioQueue=true; flagPQ=1;}
					if(pq.top() != b && isPrioQueue){
						isPrioQueue = false;
					}else if(pq.top() == b && isPrioQueue){
						pq.pop();
					}
				}
			}
		}
		if(isStack && in>=out)
			count++;
		if(isQueue && in>=out)
			count++;
		if(isPrioQueue && in>=out)
			count++;
		if(count>1 || out==0)
			cout << "not sure\n";
		else if(isStack && in>=out)
			cout << "stack\n";
		else if(isQueue && in>=out)
			cout << "queue\n";
		else if(isPrioQueue && in>=out)
			cout << "priority queue\n";
		else
			cout << "impossible\n";
	}
	return 0;
}