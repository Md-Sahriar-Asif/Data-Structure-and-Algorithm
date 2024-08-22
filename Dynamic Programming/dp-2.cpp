// Minimum coin change => min num of coins to make change
//  of given amount using given coins(infinite supply of coins)

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n, w;
    cin >> n >> w;
    int coins[n], a[n][w+1];
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    for(int j=0; j<=w; j++){
        if(j % coins[0] == 0){
            a[0][j] = j/coins[0];
        }
        else{
            a[0][j] = INT_MAX - 1;
        }
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=w; j++){
            if(coins[i] > j){
                a[i][j] = a[i-1][j];
            }
            else{
                a[i][j] = min(a[i-1][j], 1+a[i][j-coins[i]]);
            }
        }
    }

    if(a[n-1][w] == INT_MAX - 1){
        cout << -1 << endl;
    }else{
        cout << a[n-1][w] << endl;
    }
}