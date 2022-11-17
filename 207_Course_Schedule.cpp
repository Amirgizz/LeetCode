class Solution {
public:
    bool dfs(int v, vector<vector<int>> &g, vector<int> &used) {
        used[v] = 1;
        for (int to: g[v]) {
            if (used[to] == 1) {
                return false;
            }
            if (used[to] == 0) {
                if (!dfs(to, g, used)) {
                    return false;
                }
            }
        }
        used[v] = 2;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        for (auto p: prerequisites) {
            int a = p[0];
            int b = p[1];
            g[a].push_back(b);
        }
        vector<int> used(n, 0);
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0 && !dfs(i, g, used)) {
                return false;
            }
        }
        return true;
    }
};
