class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int all = 0;
        for (int i = 0; i < n; ++i) {
            cur += nums[i] * i;
            all += nums[i];
        }
        int maxx = cur;
        for (int i = 0; i < n; ++i) {
            cur += all;
            cur -= nums[n - 1 - i] * n;
            maxx = max(maxx, cur);
        }
        return maxx;
    }
};
