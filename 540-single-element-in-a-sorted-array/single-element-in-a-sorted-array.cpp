class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // Make mid even so it always points to the first element of a pair
            if (mid % 2 == 1)
                mid--;

            // Pair is valid, so the single element is on the right
            if (nums[mid] == nums[mid + 1]) {
                s = mid + 2;
            }
            // Pair is broken, so the single element is at mid or on the left
            else {
                e = mid;
            }
        }

        // s == e, pointing to the single element
        return nums[s];
    }
};