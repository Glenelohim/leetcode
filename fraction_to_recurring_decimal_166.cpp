class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!denominator)
        {
        	return NULL;
        }
        string res = "";
        int _num = numerator / denominator;
        int _den = numerator % denominator;
        res += to_string(_num);
        if (!_den)
        {
        	return res;
        }
        else
        {
        	res += ".";
        }
    }
};