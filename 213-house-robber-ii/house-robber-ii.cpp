class Solution {
public:
    int f(int i,vector<int>& nums,int e,vector<int> &dp){
        //base case to break recursion
        if(i>e)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(nums[i]+f(i+2,nums,e,dp),f(i+1,nums,e,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        return max(f(0,nums,n-2,dp1),f(1,nums,n-1,dp2));
    }
};