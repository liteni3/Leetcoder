class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1,mid,ans;
        while(s<=e){
            mid=(s+e)/2;
             //check if right array or left array which is sorted and then check for the condition on which part the target lies
            //if left part is sorted 
            if(nums[mid]==target)return mid;
            if(nums[mid]>=nums[s]){
                //now we will check if this target lies in this sorted array or not
                if(target>=nums[s] && target <nums[mid]){
                    e=mid-1;
                }else {
                    s=mid+1;
                }
            }
            //if right part is sorted 
            else {
             if(target>nums[mid] && target <=nums[e]){
                  s=mid+1;
             }else {
                e=mid-1;
             }
            }
        }
         return -1;
    }
};