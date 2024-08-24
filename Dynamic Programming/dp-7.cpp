// Partition equal subset sum

#include<bits/stdc++.h>
using namespace std;

bool solve(int index, int arr[], int n, int target, vector<vector<int>>& dp){  //top down approach
    if(index >= n || target < 0)
        return 0;
    if(target == 0)
        return 1;
    if(dp[index][target] != -1)
        return dp[index][target];
    
    bool incl = solve(index+1, arr, n, target - arr[index], dp);
    bool excl = solve(index+1, arr, n, target - 0, dp);

    return dp[index][target] = incl or excl;
}

bool solve2(int n, int arr[], int total){  //Bottoam up approach

    vector<vector<int>> dp(n+1, vector<int>(total+1, 0));

    for(int i=0; i<=n; i++)
        dp[i][0] = 1;
    
    for(int index=n-1; index>=0; index--){
        for(int target=0; target<=total/2; target++){
            bool incl = 0;
            if(target - arr[index] >= 0)
                incl = dp[index+1][target - arr[index]];
            bool excl = dp[index+1][target - 0];

            dp[index][target] = incl or excl;
        }
    }
    return dp[0][total/2];

}

int main(){
    int n;
    cin >> n;
    int arr[n];
    int total = 0;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        total += arr[i];
    }

    if(total & 1){
        cout << "No solution" << endl;
    }
    // else{
    //     int target = total/2;
    //     vector<vector<int>> dp(n, vector<int> (target+1, -1));
    //     if(solve(0, arr, n, target, dp)){
    //         cout << "There is an answer" << endl;
    //     }else{
    //         cout << "No solution" << endl;
    //     }
    // }

    else{
        if(solve2(n, arr, total)){
            cout << "There is an answer" << endl;
        }else{
            cout << "No solution" << endl;
        }
    }

    
    
}