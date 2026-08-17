class Solution {
public:
    void f(vector<vector<int>> &ans,int i,vector<int>& nums,vector<int> &ref){
        if(i>=nums.size()){
            ans.push_back(ref);
            return ;
        }
        //pick 
        ref.push_back(nums[i]);
        f(ans,i+1,nums,ref);
        // not pick
        ref.pop_back();
        f(ans,i+1,nums,ref);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
            vector<int> ref;
            f(ans,0,nums,ref);
        return ans;
    }
};