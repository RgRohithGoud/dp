#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string s,int i ,int j){
    while(i<j){
        if(s[i]!=s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
int dp[1001][1001];
int solve(string s,int i,int j){
    if(i>=j) return 0;
    if(ispalindrome(s,i,j)) return dp[i][j]= 0;
    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][k] = solve(s,i,k);
        dp[k+1][j] = solve(s,k+1,j);
        int ans = 1+dp[i][k]+dp[k+1][j];
        if(ans<mn){
            mn= ans;
        }
    }
    return dp[i][j] =  mn;
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    memset(dp,-1,sizeof(dp));
    int ans = solve(s,0,n-1);
    cout<<ans<<endl;
    return 0;
}