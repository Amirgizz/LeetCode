class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        unsigned int l = 0;
        unsigned int r = nums.size();
        while (l + 1 < r) {
            unsigned int m = (l + r) >> 1;
            if (nums[m - 1] < nums[m]) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};
