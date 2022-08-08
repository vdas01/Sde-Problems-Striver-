//1) Most optimal:- using combination
//total directions = m+n-2
//max right direction = col-1 or m-1
//max down direcion = row-1 or n-1
// So no of paths = m+n-2 C m-1 or (m+n-2 C n-1)
#include <bits/stdc++.h>
using namespace std;
void count(int n,int m){
    
    int total = (m+n)-2;
    int c1 =1;
    int r = n-1;
    for(int i=1;i<=r;i++){       //counting max right direction
        c1*= ((total-r)+i)/(i);
    } 
    cout<<c1<<" ";
}

//2)Memo and Tabulation:-
class Solution {
public:
    int result(int i,int j,int m,int n,vector<vector<int>>dp){
        int steps =0;
        if(i ==m-1 || j== n-1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        steps+= result(i+1,j,m,n,dp);
        steps+= result(i,j+1,m,n,dp);
        return dp[i][j] = steps;
    }
    int uniquePaths(int m, int n) {
         vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[m-1][n-1]=1;
        for(int j=0;j<n;j++)
            dp[0][j] = 1;
        for(int i=0;i<m;i++)
            dp[i][0]=1;
        // return result(0,0,m,n,dp);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
