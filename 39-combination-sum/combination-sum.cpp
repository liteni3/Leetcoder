class Solution {
public:
    void f(int i,vector<vector<int>> &ans,vector<int>& nums,int target,vector<int> ref,int cnt){
        if(cnt > target || i >= nums.size()) return;
            if(cnt==target){
                ans.push_back(ref);
                return ;
            }
        //pick 
        ref.push_back(nums[i]);
        f(i,ans,nums,target,ref,cnt+nums[i]);
        ref.pop_back();
        f(i+1,ans,nums,target,ref,cnt);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // any number of times - each element can be picked any number of times 
        vector<vector<int>> ans;
        vector<int> ref;
        int cnt=0;
        f(0,ans,candidates,target,ref,cnt);
        return ans;
    }
};