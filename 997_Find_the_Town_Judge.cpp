class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n + 1, 0);
        vector<bool> canbe(n + 1, true);
        for (int i = 0; i < trust.size(); ++i) {
            canbe[trust[i][0]] = false;
            ++trusted[trust[i][1]];
        }
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            if (trusted[i] == n - 1 && canbe[i]) {
                if (ans == -1) {
                    ans = i;
                } else {
                    return -1;
                }
            }
        }
        return ans;
    }
};
