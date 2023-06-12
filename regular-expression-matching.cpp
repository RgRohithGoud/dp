    #include <bits/stdc++.h>
    using namespace std;
    int dp[21][21];
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        memset(dp,-1,sizeof(dp));
        dp[0][0] =1;
        for(int i=1;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*') dp[0][i] = dp[0][i-2];
            else dp[0][i] = 0; 
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i]==p[j] || p[j]=='.'){
                    dp[i+1][j+1] = dp[i][j];
                }else if(p[j] == '*'){
                    dp[i+1][j+1] = dp[i+1][j-1];    
                    if(p[j-1]==s[i] || p[j-1]=='.'){
                        dp[i+1][j+1]  =dp[i+1][j+1]||dp[i][j+1];
                    }
                    /* check whether without taking before char in pattern is matching      
                    expression
                    ex: X, XA* => here without taking A its mathing ==> case 1
                    ex; XAA, XA* => XA, XA => 2nd A in s ,matches A in p. */
                } else dp[i+1][j+1] = 0;
            }
        }
        return dp[n][m];
    }
    int main(){
        string s,p;
        cin>>s>>p;
        bool x = isMatch(s,p);
        cout<<x<<endl;
        return 0;
    }