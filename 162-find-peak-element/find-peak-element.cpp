class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0,e=nums.size()-1,mid;
        if(nums.size()==1)return 0;
        while(s<=e){
            mid=(s+e)/2;
               if(mid==0){
                if(nums[mid]>nums[1])return 0;
                else s=mid+1;
               }
               else if (mid==nums.size()-1){
                if(nums[mid]>nums[mid-1])return mid;
                else e=mid-1;
               }
               else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])return mid;
               else if(nums[mid]<nums[mid+1]){
                s=mid+1;
               }
               else if(nums[mid]<nums[mid-1]){
                e=mid-1;
               }
        }
        return 0;
    }
};