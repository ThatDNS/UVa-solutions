// Problem: 259 - Software Allocation

/* in the array res: (location of different vertices at different indices)
source: 0
A...Z: 1...26
Computers(10): 27...36
sink: 37
*/

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

int res[40][40], mf, f, s, t;
vi p;

void Augment(int v, int minEdge);

int main(){
	string str, temp;
	int no, alph, total;
	char c;
	while(getline(cin, str)){
		memset(res, 0, sizeof res); total=0;
		for(int i=27; i<=36; i++)
			res[i][37] = 1;
		c = str[0]; alph = (int)c - 64;
		temp = str[1]; no = stoi(temp);
		res[0][alph] += no;
		total += no;
		for(int i=0; ; i++){
			temp = str[3+i];
			if(temp == ";") break;
			res[alph][stoi(temp)+27] = 1;
		}
		while(getline(cin, str) && str!=""){
			c = str[0]; alph = (int)c - 64;
			temp = str[1]; no = stoi(temp);
			res[0][alph] += no;
			total += no;
			for(int i=0; ; i++){
				temp = str[3+i];
				if(temp == ";") break;
				res[alph][stoi(temp)+27] = 1;
			}
		}
		s = 0; t = 37;
		mf = 0;
		while(1){
			f = 0;
			vi dist(40, INF);
			dist[s] = 0;
			queue<int> q; q.push(s);
			p.assign(40, -1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u == t) break;
				for(int v = 0; v<40; v++){
					if(res[u][v] > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
				}
			}
			Augment(t, INF);
			if(f == 0) break;
			mf += f;
		}
		if(mf == total){
			for(int i=27; i<=36; i++){
				alph = -1;
				for(int j=1; j<=26; j++){
					if(res[i][j] == 1){
						alph = j;
						break;
					}
				}
				if(alph != -1)
					cout << (char)(alph+64);
				else
					printf("_");
			}
			printf("\n");
		}else{
			printf("!\n");
		}
	}
	return 0;
}

void Augment(int v, int minEdge){
	if(v==s){
		f = minEdge;
		return;
	}else if(p[v] != -1){
		Augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

