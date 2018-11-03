// Problem: 11947 - Cancer or Scorpio
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
int totalDays(int month, int year);
string getZodiac(int dd, int mm);
int netDays_N[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int netDays_L[] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
	short int n, curr=1, currD, currM, currY;
	string s, dd, mm, yy;
	cin >> n;
	while(n--){
		cin >> s;
		mm = s.substr(0, 2);
		dd = s.substr(2, 2);
		yy = s.substr(4, 4);
		currD = stoi(dd); currM = stoi(mm); currY = stoi(yy);
		for(int i=0; i<280; i++){ // 280 times loop
			++currD;
			if(currD == totalDays(currM, currY)+1){
				currD = 1;
				++currM;
				if(currM == 13){
					currM = 1; ++currY;
				}
			}
		}
		if(currM>=10 && currD>=10){
			printf("%d %d/%d/%d ", curr++, currM, currD, currY);
			cout << getZodiac(currD, currM) << endl;
		}else if(currM<10 && currD<10){
			printf("%d 0%d/0%d/%d ", curr++, currM, currD, currY);
			cout << getZodiac(currD, currM) << endl;
		}else if(currM<10 && currD>=10){
			printf("%d 0%d/%d/%d ", curr++, currM, currD, currY);
			cout << getZodiac(currD, currM) << endl;
		}else if(currM>=10 && currD<10){
			printf("%d %d/0%d/%d ", curr++, currM, currD, currY);
			cout << getZodiac(currD, currM) << endl;
		}
	}
	return 0;
}

int totalDays(int month, int year){
	if(year%4 == 0)
		return netDays_L[month];
	return netDays_N[month];
}

string getZodiac(int dd, int mm){
	if((mm==1 && dd>=21) || (mm==2 && dd<=19))
		return "aquarius";
	else if((mm==2 && dd>=20) || (mm==3 && dd<=20))
		return "pisces";
	else if((mm==3 && dd>=21) || (mm==4 && dd<=20))
		return "aries";
	else if((mm==4 && dd>=21) || (mm==5 && dd<=21))
		return "taurus";
	else if((mm==5 && dd>=22) || (mm==6 && dd<=21))
		return "gemini";
	else if((mm==6 && dd>=22) || (mm==7 && dd<=22))
		return "cancer";
	else if((mm==7 && dd>=23) || (mm==8 && dd<=21))
		return "leo";
	else if((mm==8 && dd>=22) || (mm==9 && dd<=23))
		return "virgo";
	else if((mm==9 && dd>=24) || (mm==10 && dd<=23))
		return "libra";
	else if((mm==10 && dd>=24) || (mm==11 && dd<=22))
		return "scorpio";
	else if((mm==11 && dd>=23) || (mm==12 && dd<=22))
		return "sagittarius";
	else if((mm==12 && dd>=23) || (mm==1 && dd<=20))
		return "capricorn";
	return "0";
}
