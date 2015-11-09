class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty())
        	return vector<int>(1, 1);
        
        vector<int>::iterator iter = digits.end() - 1;
        if (*iter < 9)
        {
        	*iter = *iter + 1;
        	return digits;
        }
        while (*iter == 9 && iter != digits.begin())
        {
        	*iter = 0;
        	iter --;
        }
        if (iter == digits.begin() && *iter == 9)
        {
        	*iter = 0;
        	digits.insert(digits.begin(), 1);
        }
        else
        	*iter = *iter + 1;
        return digits; 
    }
};