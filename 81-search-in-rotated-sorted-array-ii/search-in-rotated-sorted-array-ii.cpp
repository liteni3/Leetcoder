class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Brutforce - O(N)
        int s=0;
        int n=nums.size();
        int e=n-1;
        // edge case if size ==1 
            while(nums[s]==nums[e]){
            if(nums[s]==target)return true;
            if(n>1){
                s=s+1;
                n=n-1;
            }else if(n==1){
                if(nums[s]!=target)return false;
            }
        }
        int mid;
        while(s<=e){
            mid = (s+e)/2;
            if(nums[mid]==target)return true;
            // if left is sorted ?
            if(nums[mid]>=nums[s]){
                // if lies in sorted region
                if(target < nums[mid] && target >= nums[s]){
                    e=mid-1;
                }else {
                    s= mid+1;
                }
            }
            //right is sorted if left is not because either of them will have to be sorted 
            else {
                if(nums[mid]<target && nums[e]>=target){
                    s=mid+1;
                }else {
                    e=mid-1;
                }
            }
        }
            return false;
    }
};