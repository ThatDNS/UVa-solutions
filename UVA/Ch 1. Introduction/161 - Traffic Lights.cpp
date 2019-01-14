// Problem: 161 - Traffic Lights
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
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

vi signals, state, counter; //1:green, 2:orange, 3:red
bool checkAllGreen();
void convert(int secs);

int main(){
	int secs=0, t, a, b, c, cc=0;
	while(1){
		while(cin >> t && t!=0){
			signals.pb(t);
			state.pb(1);
			counter.pb(t-5);
		}
		bool update=false;
		while(secs <= 18000){
			for(int i=0; i<signals.size(); i++){
				if(counter[i] == 0){
					if(state[i]==1){
						counter[i] = 4;
						state[i] = 2;
					}else if(state[i]==2){
						counter[i] = signals[i]-1;
						state[i] = 3;
					}else if(state[i]==3){
						counter[i] = signals[i]-6;
						state[i] = 1;
					}
					update = true;
				}else{
					--counter[i];
				}
			}
			if(update && checkAllGreen())
				break;
			else
				++secs;
		}
		if(secs <= 18000)
			convert(secs);
		else
			printf("Signals fail to synchronise in 5 hours\n");
		signals.clear();
		state.clear();
		counter.clear();
		secs = 0;
		cin >> a;
		if(a==0){
			cin >> b;
			if(b==0){
				cin >> c;
				if(c==0){
					break;
				}else{
					signals.pb(c);
					state.pb(1);
					counter.pb(c-5);
				}
			}else{
				signals.pb(b);
				state.pb(1);
				counter.pb(b-5);
			}
		}else{
			signals.pb(a);
			state.pb(1);
			counter.pb(a-5);
		}
	 }
	
	return 0;
}

bool checkAllGreen(){
	for(int i=0; i<signals.size(); i++){
		if(state[i] != 1)
			return false;
	}
	return true;
}

void convert(int secs){
	int hr=0, s=0, min=0;
	while(secs >= 3600){
		secs -= 3600;
		++hr;
	}
	while(secs >= 60){
		secs -= 60;
		++min;
	}
	s = secs;

	if(s >= 10){
		if(min >= 10){
			if(hr>0)
				printf("0%d:%d:%d\n", hr, min, s);
			else
				printf("00:%d:%d\n", min, s);
		}else{
			if(hr>0)
				printf("0%d:0%d:%d\n", hr, min, s);
			else
				printf("00:0%d:%d\n", min, s);
		}
	}else{
		if(min >= 10){
			if(hr>0)
				printf("0%d:%d:0%d\n", hr, min, s);
			else
				printf("00:%d:0%d\n", min, s);
		}else{
			if(hr>0)
				printf("0%d:0%d:0%d\n", hr, min, s);
			else
				printf("00:0%d:0%d\n", min, s);
		}
	}
	return;
}
