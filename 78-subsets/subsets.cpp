class Solution {
public:
    void f(vector<int> ref,vector<int> &nums,int k,vector<vector<int>> &ans){
         //base case
         if(k==nums.size()){
             ans.push_back(ref);
             return;
         }
         
         //pick condition
         ref.push_back(nums[k]);
         f(ref,nums,k+1,ans);

         //not pick condition
        ref.pop_back();
        f(ref,nums,k+1,ans);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //Pick not pick k liye do recursive functions call kardenge har ek
        //element par
        vector<int> ref;
        vector<vector<int>> ans;
        int k=0;
        f(ref,nums,k,ans);
        return ans;
    }
};