// Nth fibonacci number

#include<bits/stdc++.h>
using namespace std;

// int fib(int n, vector<int> dp){  //top down approach
    
//     if(n <= 1){
//         return n;
//     }
//     if(dp[n] != -1){
//         return dp[n];
//     }

//     dp[n] = fib(n-1, dp) + fib(n-2, dp);
//     return dp[n];
// }

int fib(int n, vector<int> dp){  // Bottom up approach
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int fib(int n){   //space optimisation approach
    
    if(n==0)
        return 0;

    int prev1 = 1;
    int prev2 = 0;

    for(int i=2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n; 
    cin >> n;
     
     vector<int> dp(n+1);
     for(int i=0; i<=n; i++){
        dp[i] = -1;
     }
    cout << fib(n) << endl;
}