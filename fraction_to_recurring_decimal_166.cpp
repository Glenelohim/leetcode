class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!denominator)
        {
        	return NULL;
        }
        if (!numerator)
        {
            return "0";
        }
        string res = "";
        if (numerator < 0 ^ denominator < 0)
        {
            res += "-";
        }

        long long _num = numerator < 0 ? (long long)numerator * (-1): numerator;
        long long _den = denominator < 0 ? (long long)denominator * (-1): denominator;
        long long num = _num / _den;
        long long den = _num % _den;
        res += to_string(num);
        if (!den)
        {
        	return res;
        }
        else
        {
        	res += ".";
        }
        unordered_map<long long, int> u_map;
        num = den * 10;
        while (num)
        {
            if (u_map.find(num) != u_map.end())
            {
                res.insert(u_map[num], 1, '(');
                res += ")";
                break;
            }
            u_map[num] = res.size();
            long long p = num / _den;
            res += to_string(p);
            num %= _den;
            num *= 10;
        }
        return res;
    }
};