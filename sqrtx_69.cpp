class Solution {
public:
	//awesome solution from the discuss
	//sqrt(N) = 2sqrt(N/4)
    int mySqrt(int x) {
        if (0 == x)
        	return 0;
        if (x < 4)
        	return 1;
        int res = 2 * mySqrt(x / 4);
        if ((res + 1) * (res + 1) >= 0 && (res + 1) * (res + 1) <= x)
        	return res + 1;
        return res;
    }
};