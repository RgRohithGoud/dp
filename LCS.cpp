#include <bits/stdc++.h>
using namespace std;
int dp[1006][1006];
int ans(string a,string b,int n,int m){
    for(int i=0;i<=n;i++){
        dp[i][0]= 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                dp[i+1][j+1] = 1+dp[i][j];
            }
            else{
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[n][m];
}
int solve(string A, string B) {
    int n = A.length();
    int m = B.length();
    memset(dp,0,sizeof(dp));
    return ans(A,B,n,m);
}
int main(){
    return 0;
    string a;
    string b;
    solve(a,b);
}
