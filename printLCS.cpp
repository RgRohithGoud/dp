#include <bits/stdc++.h>
using namespace std;
    int dp[1001][1001];
    string ans(string a, string b, int n,int m){
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<m;i++){
            dp[0][i] = 0;
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
        int x=0;
        string s ="";
        int i = n,j=m;
        while(i>0&j>0){
            if(a[i-1]==b[j-1]){
                s.push_back(a[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else j--;
            }
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
    void solve(string a,string b){
        int n = a.length();
        int m = b.length();
        memset(dp,-1,sizeof(dp));
        string abc = ans(a,b,n,m);
    }

int main(){
    string a;
    string b;
    cin>>a;
    cin>>b;
    solve(a,b);
    return 0;
}