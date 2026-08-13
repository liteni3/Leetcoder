class Solution {
public:
    void f(vector<int>& candidates,int target,vector<vector<int>> &ans,vector<int> &v,int ref,int i){
        //base 
        if(ref > target || i >= candidates.size()) return;
        if(ref==target){
            ans.push_back(v);
            return;
        }
        //take
        v.push_back(candidates[i]);
        f(candidates,target,ans,v,ref+candidates[i],i);
        v.pop_back();
        f(candidates,target,ans,v,ref,i+1);

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int ref=0;
        f(candidates,target,ans,v,ref,0);
        return ans;
        
    }
};