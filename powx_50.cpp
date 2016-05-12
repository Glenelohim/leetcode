class Solution {
public:
    double myPow(double x, int n) {
        if (0 == n)
        	return 1;
        if (1 == n)
        	return x;
        bool isNeg = false;
        long long temp_n = n;
        if (temp_n < 0)
        {
        	temp_n = -temp_n;  //may cause overflow
        	isNeg = true;
        }
        double res = 1;
        while (temp_n > 0)
        {
        	if (temp_n % 2 != 0)
        	{
        		res *= x;
        	}
        	x = x * x;
        	temp_n /= 2;
        }
        if (isNeg)
        {
        	res = 1 / res;
        }
        return res;
    }
};