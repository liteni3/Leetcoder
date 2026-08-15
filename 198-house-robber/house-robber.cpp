class Solution {
public:
    int f(vector<int>& nums,int i,vector<int> &dp){
        //base case 
        if(i>=nums.size()) return 0;
        //take this house then if taking only can take i+2
        if(dp[i]!=-1)return dp[i];
        return dp[i]= max (nums[i] + f(nums,i+2,dp),f(nums,i+1,dp));

    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,0,dp);
    }
};