#include <cmath>
#include <utility>
#include <set>

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 20 * int(1e8);
        set<pair<int, int>> us{};
        for (int i = 0; i < n; ++i) {
            us.insert({points[i][0], points[i][1]});
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int ax = points[i][0];
                int ay = points[i][1];
                int bx = points[j][0];
                int by = points[j][1];
                if (ax != bx && ay != by && us.find({ax, by}) != us.end() && us.find({bx, ay}) != us.end()) {
                    ans = min(ans, abs((ax-bx)*(ay-by)));
                }
            }
        }
        if (ans == 20 * int(1e8)) {
            return 0;
        }
        return ans;
    }
};
