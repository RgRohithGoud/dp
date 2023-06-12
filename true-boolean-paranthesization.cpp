#include <bits/stdc++.h>
using namespace std;

//T^F&T|T
int dp[1001][1001][2];
int solve(string s,int i,int j,bool b){
    if(i>j) return true;
    if(i==j){
        if(s[i]-'0'==b){
            return true;
        }
        else return false;
    }
    if(dp[i][j][b]!=-1) return dp[i][j][b];
    int ans =0;
    for(int k = i+1;k<=j-1;k = k+2){
        int LT = solve(s,i,k-1,true);
        dp[i][k-1][1] = LT;
        int LF = solve(s,i,k-1,false);
        dp[i][k-1][0] = LF;
        int RT = solve(s,k+1,j,true);
        dp[k+1][j][1] = RT;
        int RF = solve(s,k+1,j,false);
        dp[k+1][j][0] = RF;
        if(s[k]=='|'){
            if(b==true) ans += LT*RT + LT*RF + LF*RT;
            else ans+= LF*RF;
        }
        if(s[k]=='&'){
            if(b==false) ans += LF*RF + LT*RF + LF*RT;
            else ans += LT*RT;
        }
        if(s[k]=='^'){
            if(b==true) ans += LT*RF + LF*RT;
            else ans += LF*RF + RT*LT;
        }
    }
    return dp[i][j][b] = ans;
}
int main(){
    string s;
    cin>>s;
    int n = s.length();
    memset(dp,-1,sizeof(dp));
    int x = solve(s,0,n-1,true);
    cout<<x<<endl;
    return 0;
}