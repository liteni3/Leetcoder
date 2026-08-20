class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int n=nums.size();
        int e=n-1;
        int mid;
        while(s<=e){
            mid=(s+e)/2;
            if(nums[mid]==target)return mid;
            //if left is sorted ?
            if(nums[mid]>=nums[s]){
                if(nums[mid]>=target && target >=nums[s]){
                    e=mid-1;
                }else {
                    s=mid+1;
                }
            }
            // right is sorted ?
            else if(nums[mid]<=nums[e]) {
                if(target >=nums[mid] && target <=nums[e]){
                    s=mid+1;
                }else {
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};
/* 
[4,5,6,7,0,1,2] , 0
7

*/