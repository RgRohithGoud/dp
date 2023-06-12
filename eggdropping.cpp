#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int e,int f){
    if(e==0) return 0;
    if(e==1) return f;
    if(dp[e][f]!=-1) return dp[e][f];
    if(f==0|| f==1) return f;
    int ans = INT_MAX;
    for(int k=1;k<=f;k++){
        int temp = 1+max(dp[e-1][k-1] = solve(e-1,k-1),dp[e][f-k] =  solve(e,f-k));
        ans = min(ans,temp);
    }
    return dp[e][f] = ans;
}
int main(){
    int e,f;
    cin>>e>>f;
    memset(dp,-1,sizeof(dp));
    int i = solve(e,f);
    cout<<i<<endl;
    return 0;
}