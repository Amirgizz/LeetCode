class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res(nums.size());
        int it = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) {
                res[i] = nums[(nums.size() + 1) / 2 + it];
                ++it;
            } else {
                res[i] = nums[it];
            }
        }
        return res;
    }
};
