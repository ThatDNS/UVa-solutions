// Problem: 1062 - Containers
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
vector<stack<char> > strVec;
void addToStack(char c);
int main(){
	string s;
	char c;
	int test=0;
	while(cin >> s && s != "end"){
		strVec.clear();
		for(int i=0; i<s.length(); i++){
			c = s[i];
			addToStack(c);
		}
		printf("Case %d: %lu\n", ++test, strVec.size());
	}
	return 0;
}

void addToStack(char c){
	stack<char> S;
	if(strVec.size()==0){
		S.push(c);
		strVec.push_back(S);
		return;
	}else{
		for(int i=0; i<strVec.size(); i++){
			if(c <= strVec[i].top()){
				strVec[i].push(c);
				return;
			}
		}
		S.push(c);
		strVec.push_back(S);
	}
}
