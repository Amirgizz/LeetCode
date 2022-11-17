class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                d[i + 1][j + 1] = d[i + 1][j] + d[i][j + 1] - d[i][j] + mat[i][j];
                int l = ans, r = min(i, j) + 2;
                while (l + 1 < r) {
                    int m = (l + r) / 2;
                    if (d[i + 1][j + 1] - d[i + 1][j + 1 - m] - d[i + 1 - m][j + 1] + d[i + 1 - m][j + 1 - m] <= threshold) {
                        l = m;
                    } else {
                        r = m;
                    }
                }
                ans = l;
            }
        }
        return ans;
    }
};
