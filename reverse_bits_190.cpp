class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	uint32_t res = 0;
        for (int i = 1; i <= 32; i++)
        {
        	uint32_t temp = n % 2;
        	n /= 2;
        	res = res * 2 + temp;
        }
        return res;
    }
};