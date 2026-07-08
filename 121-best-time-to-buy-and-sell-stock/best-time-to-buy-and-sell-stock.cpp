class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans=0;
        int mini=INT_MAX,maxi=0;
         for(int i=0;i<arr.size();i++){
             ans=max(ans,arr[i]-mini);
             mini=min(arr[i],mini);
         }
         return ans;
    }
};