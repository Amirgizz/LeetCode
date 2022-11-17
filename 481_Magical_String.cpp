class Solution {
public:
    int magicalString(int n) {
        vector<int> v = {1, 2, 2};
        for (int i = 2; v.size() < n; ++i) {
            if (v[i] == 1) {
                if (v.back() == 1) {
                    v.push_back(2);
                } else {
                    v.push_back(1);
                }
            } else {
                if (v.back() == 1) {
                    v.push_back(2);
                    v.push_back(2);
                } else {
                    v.push_back(1);
                    v.push_back(1);
                }
            }
        }
        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] == 1) {
                ++c;
            }
        }
        return c;
    }
};
