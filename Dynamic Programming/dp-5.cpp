// Longest common subsequence

#include<bits/stdc++.h>
using namespace std;

int solve(string& a, string& b, int i, int j, vector<vector<int>> &dp){  //Top down approach

    if(i == a.length() || j==b.length()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(a[i] == b[j]){
        ans = 1 + solve(a, b, i+1, j+1, dp);
    }
    else{
        ans = max(solve(a, b, i+1, j, dp), solve(a, b, i, j+1, dp));
    }
    return dp[i][j] = ans;
}

int solve2(string a, string b){ //Bottom up approach
    vector<vector<int>> dp2(a.length()+1, vector<int>(b.length()+1, 0));

    for(int i=a.length()-1; i>=0; i--){
        for(int j=b.length()-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j]){
                ans = 1 + dp2[i+1][j+1];
            }
            else{
                ans = max(dp2[i+1][j], dp2[i][j+1]);
            }
            dp2[i][j] = ans;
        }
    }
    return dp2[0][0];
}

int main(){
    string text1, text2;
    cin >> text1 >> text2;
    
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    //cout << solve(text1, text2, 0, 0, dp) << endl;

    cout << solve2(text1, text2) << endl;
}