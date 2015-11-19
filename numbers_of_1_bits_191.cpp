class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
        	uint32_t temp = n % 2;
        	n /= 2;
        	if (temp)
        		res++;
        }
        return res;
    }
};