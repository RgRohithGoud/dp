// Problem Statement

// Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

// Input Format
// Number of workers and job: N
// Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

// Sample Input
// 4

// [
// 9 2 7 8
// 6 4 3 7
// 5 8 1 8
// 7 6 9 4
// ]

// Sample Output
// 13

// Constraints
// N <= 20

// here each bit is assigned to each job ex: for 2,3 5 => 00010110 is representation of the available jobs
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int cost[20][20];
int solve(int i,int mask,int& n){
    if(i==n+1) return 0;
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ans =INT_MAX;
    for(int j=0;j<n-1;j++){
        if(mask&(1<<j)){
            ans = min(ans,cost[j][i]+solve(i,mask^(1<<j),n));
        }
    }
    return dp[i][mask]= ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    return 0;
}