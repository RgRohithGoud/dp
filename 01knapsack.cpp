#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a[n]; //values
    int b[n]; //weights
    int w; //max weight
    int dp[n+1][w+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=w;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=w;j++){
            if(b[i]<=j){
                dp[i+1][j] = max(a[i]+dp[i][j-b[i]],dp[i][j]);
            }
            else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    return dp[n][w];    
    return 0;
}