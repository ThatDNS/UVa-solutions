/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int k, n, m;
    while(cin>>k && k!=0){
        cin >> n >> m;
        int arr[k][2];
        for(int i=0; i<k; i++){
            cin >> arr[i][0] >> arr[i][1];
        }
        for(int i=0; i<k; i++){
            if(arr[i][0] == n || arr[i][1] == m){
                cout << "divisa" << endl;
            }else if(arr[i][0] > n){
                if(arr[i][1] > m){
                    cout << "NE" << endl;
                }else{
                    cout << "SE" << endl;
                }
            }else if(arr[i][0] < n){
                if(arr[i][1] > m){
                    cout << "NO" << endl;
                }else{
                    cout << "SO" << endl;
                }
            }
        }
    }
    return 0;
}