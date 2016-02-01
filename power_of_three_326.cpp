class Solution {
public:
    bool isPowerOfThree(int n) {
    	if (n < 1)	return false;
    	if (n == 1)	return true;
    	while (n > 3)
    	{
    		int temp = n % 3;
    		if (temp)	return false;
    		n /= 3;
    	}
    	if (n == 3)	return true;
    	return false;
    }
};