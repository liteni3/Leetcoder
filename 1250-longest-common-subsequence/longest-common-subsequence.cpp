class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
         int m=text1.length();
         int n=text2.length();
         //create 2D Matrix
         vector<vector<int>> dp(m+1,vector<int>(n+1,0));
         // (m+1)*(n+1) matrix 
         for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //If the chars match 
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                //if they dont match 
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
         }
         return dp[m][n];
    }
};