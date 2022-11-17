class Solution {
public:
    int dfs(int v, vector<vector<int>> &g, vector<bool> &used) {
        used[v] = true;
        int c = 1;
        for (int to: g[v]) {
            if (!used[to]) {
                c += dfs(to, g, used);
            }
        }
        return c;
    }

    int maximumDetonation(vector<vector<int>>& p) {
        int n = p.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long sq_sum = (long long)(p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (long long)(p[i][1] - p[j][1]) * (p[i][1] - p[j][1]);
                if (sq_sum <= (long long)p[i][2] * p[i][2]) {
                    g[i].push_back(j);
                }
                if (sq_sum <= (long long)p[j][2] * p[j][2]) {
                    g[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            vector<bool> used(n, false);
            ans = max(ans, dfs(i, g, used));
        }
        return ans;
    }
};
