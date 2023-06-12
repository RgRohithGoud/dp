#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int solve(int* a,int i,int j){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn= INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][k] = solve(a,i,k);
        dp[k+1][j] = solve(a,k+1,j);
        int tempans = dp[i][k]+dp[k+1][j]+ a[i-1]*a[k]*a[j];
        if(tempans<mn){
            mn= tempans;
        }
    }
    return dp[i][j] =  mn;
} 

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    int mcm =solve(a,1,n-1);
    cout<<mcm<<endl;
    return 0;
}