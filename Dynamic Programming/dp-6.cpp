// Rod cutting 

#include<bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z, vector<int> &arr){  //Top down approach

    if(n == 0)
        return 0;

    if(n < 0)
        return INT_MIN;

    if(arr[n] != -1)
        return arr[n];

    int a = solve(n-x, x, y, z, arr) + 1;
    int b = solve(n-y, x, y, z, arr) + 1;
    int c = solve(n-z, x, y, z, arr) + 1;

    arr[n] = max(a, max(b, c));

    return arr[n];
}

int solve2(int n, int x, int y, int z){  //Bottom up approach

    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        if(i-x >= 0)
            dp[i] = max(dp[i], dp[i-x] + 1);

        if(i-y >= 0)
            dp[i] = max(dp[i], dp[i-y] + 1);
        
        if(i-z >= 0)
            dp[i] = max(dp[i], dp[i-z] + 1);
    }
    if(dp[n] < 0)
        return 0;
    else
        return dp[n];
}

int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    // vector<int> arr(n+1, -1);
    // int ans = solve(n, x, y, z, arr);
    // if(ans < 0)
    //     cout << "No solution" << endl;
    // else
    //     cout << ans << endl;

    int ans2 = solve2(n, x, y, z);
    if(ans2)
        cout << ans2 << endl;
    else
        cout << "No solution" << endl;
}