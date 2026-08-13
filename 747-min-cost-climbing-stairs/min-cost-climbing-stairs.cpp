class Solution {
public:
    int f(int n,int ans,vector<int>& cost,vector<int> &dp){
        // base case for recursion
        if(n==1) return cost[1];
        if(n==0) return cost[0];
        if(dp[n]!=-1)return dp[n];
        return dp[n] = cost[n] + min(f(n-1,ans,cost,dp),f(n-2,ans,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        // n <1 , n+1 , n+2
        int ans=0;
        vector<int> dp(n+1,-1);
        return min(f(n-1,ans,cost,dp),f(n-2,ans,cost,dp));
    }
};