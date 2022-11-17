#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long a = 0; a * a <= c; ++a) {
            int b2 = c - a * a;
            int b = sqrt(b2);
            if (b * b + a * a == c) {
                return true;
            }
        }
        return false;
    }
};
