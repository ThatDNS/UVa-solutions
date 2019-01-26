// Problem: 10920 - Spiral Tap
/* Concept:
The obvious method of doing this problem is simulating the problem but it'll give you a TLE.
You can see that this spiral pattern creates concentric "rings" of squares. So I firstly found the
ring containing the answer and then simulated the problem on THAT ring only to reach the answer.
This solution is accepted within time limit.
*/
/**
 *	Author: Fallen_Cryptic
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;
#define EPS 1e-9 // 10^-9
#define pb push_back
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define For0(i,n) for(int i=0; i<n; i++)
#define For(i,a,b) for(int i=0; i<n; i++)
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

void move(int direc);
int changeDirec(int currDirec);
int x, y;


int main(){
	int sj;
	long long p, counter=0;
	int direc; //0:up, 1:left, 2:down, 3:right
	int totalTimes, timesMoved, timesChange;
	long long ring, boxesCovered, oddNo;
	long long arr[100002][100002];
	while(cin >> sj >> p){
		if(sj==0 && p==0)
			break;

		//get ring
		ring = 0;
		boxesCovered = 1;
		oddNo = 1;
		while(boxesCovered < p){
			boxesCovered += oddNo*4 + 4;
			oddNo += 2;
			++ring;
		}
		if(ring == 0){ //Special Case
			printf("Line = %d, column = %d.\n", sj/2 + 1, sj/2 + 1);
			continue;
		}

		x = sj/2 + 1 + ring;
		y = sj/2 + ring;
		oddNo -= 2;
		counter=boxesCovered - oddNo*4 - 3; direc=1;
		totalTimes=oddNo; timesMoved=0;
		timesChange=0;
		bool isFirst = true;
		while(1){
			arr[x][y] = counter;
			if(counter == p)
				break;

			//move
			move(direc);
			++timesMoved;
			++counter;

			//change direc
			if(timesMoved == totalTimes){
				direc = changeDirec(direc);
				timesMoved=0;
				++timesChange;
				if(timesChange == 2 || isFirst){
					isFirst = false;
					timesChange = 0;
					++totalTimes;
				}
			}
			if(counter == sj*sj)
				break;
			if(x == sj && y == sj)
				break;
		}

		printf("Line = %d, column = %d.\n", x, y);

	}
	return 0;
}

void move(int direc){
	if(direc==0){
		x += 1;
	}else if(direc==1){
		y -= 1;
	}else if(direc==2){
		x -= 1;
	}else if(direc==3){
		y += 1;
	}
}

int changeDirec(int currDirec){
	if(currDirec < 3)
		return currDirec+1;
	return 0;
}


