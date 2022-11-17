class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int pl = num1.find('+');
        int ar = stoi(num1.substr(0, pl));
        int ai = stoi(num1.substr(pl + 1, num1.size() - (pl + 2)));
        pl = num2.find('+');
        int br = stoi(num2.substr(0, pl));
        int bi = stoi(num2.substr(pl + 1, num2.size() - (pl + 2)));
        return to_string(ar * br - ai * bi) + "+" + to_string(ai * br + ar * bi) + "i";
    }
};
