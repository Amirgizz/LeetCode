class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> d(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    d[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x > 0 && d[x - 1][y] == -1) {
                d[x - 1][y] = d[x][y] + 1;
                q.push({x - 1, y});
            }
            if (x + 1 < n && d[x + 1][y] == -1) {
                d[x + 1][y] = d[x][y] + 1;
                q.push({x + 1, y});
            }
            if (y > 0 && d[x][y - 1] == -1) {
                d[x][y - 1] = d[x][y] + 1;
                q.push({x, y - 1});
            }
            if (y + 1 < m && d[x][y + 1] == -1) {
                d[x][y + 1] = d[x][y] + 1;
                q.push({x, y + 1});
            }
        }
        return d;
    }
};
