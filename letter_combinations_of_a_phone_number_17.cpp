class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int len = digits.size();
        if (0 == len)
        {
        	return res;
        }
        if ((digits.find('0') != std::string::npos) || (digits.find('1') != std::string::npos))
        {
        	return res;
        }

        
    }
};