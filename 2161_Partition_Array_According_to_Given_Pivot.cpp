class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, same, greater;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < pivot) {
                less.push_back(nums[i]);
            } else if (nums[i] == pivot) {
                same.push_back(nums[i]);
            } else {
                greater.push_back(nums[i]);
            }
        }
        for (int x: same) {
            less.push_back(x);
        }
        for (int x: greater) {
            less.push_back(x);
        }
        return less;
    }
};
