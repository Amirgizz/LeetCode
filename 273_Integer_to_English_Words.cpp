class Solution {
public:
    string block(int a) {
        vector<string> digits = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> res;

        if (a / 100 > 0) {
            res.push_back(digits[a / 100]);
            res.push_back("Hundred");
        }
        
        if (a % 100 / 10 == 1) {
            res.push_back(teens[a % 10]);
        } else {
            if (a % 100 / 10 > 1) {
                res.push_back(tens[a % 100 / 10]);
            }
            if (a % 10 > 0 || res.empty()) {
                res.push_back(digits[a % 10]);
            }
        }
        string res_s;
        for (int i = 0; i < res.size(); ++i) {
            res_s += res[i];
            if (i + 1 < res.size()) {
                res_s.push_back(' ');
            }
        } 
        return res_s;
    }
    
    string numberToWords(int num) {
        int bill = num / int(1e9);
        int mill = num % int(1e9) / int(1e6);
        int thou = num % int(1e6) / 1000;
        int low = num % 1000;
        vector<string> blocks;
        if (bill > 0) {
            blocks.push_back(block(bill));
            blocks.push_back("Billion");
        }
        if (mill > 0) {
            blocks.push_back(block(mill));
            blocks.push_back("Million");
        }
        if (thou > 0) {
            blocks.push_back(block(thou));
            blocks.push_back("Thousand");
        }
        if (low > 0 || blocks.size() == 0) {
            blocks.push_back(block(low));
        }
        string res;
        for (int i = 0; i < blocks.size(); ++i) {
            res += blocks[i];
            if (i + 1 < blocks.size()) {
                res.push_back(' ');
            }
        } 
        return res;
    }
};
