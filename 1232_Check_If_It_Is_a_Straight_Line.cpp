class Solution {
public:

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int g = __gcd(abs(coordinates[1][0] - coordinates[0][0]), abs(coordinates[1][1] - coordinates[0][1]));
        int ax = (coordinates[1][0] - coordinates[0][0]) / g;
        int ay = (coordinates[1][1] - coordinates[0][1]) / g;

        if (ax == 0) {
            for (int i = 1; i + 1 < coordinates.size(); ++i) {
                if (coordinates[i][0] - coordinates[i + 1][0] != 0) {
                    return false;
                }
            }
            return true;
        }
        if (ay == 0) {
            for (int i = 1; i + 1 < coordinates.size(); ++i) {
                if (coordinates[i][1] - coordinates[i + 1][1] != 0) {
                    return false;
                }
            }
            return true;
        }
        
        for (int i = 1; i + 1 < coordinates.size(); ++i) {
            int dx = coordinates[i][0] - coordinates[i + 1][0];
            int dy = coordinates[i][1] - coordinates[i + 1][1];
            if (dx / ax != dy / ay || dx % ax != 0 || dy % ay != 0) {
                return false;
            }
        }
        return true;
    }
};
