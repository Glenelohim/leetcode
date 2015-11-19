//time limit exceeded
class Solution {
public:
	void countTwoAndFive(int n, int *array)
	{
		while (!(n % 2) || !(n % 5))
		{
			if (!(n % 2))
			{
				array[0]++;
				n = n / 2;
			}
			if (!(n % 5))
			{
				array[1]++;
				n = n / 5;
			}
		}
	}

    int trailingZeroes(int n) {
        if (n < 5)
        	return 0;
        int twoandfive[2] = {0, 0};
        for (int i = 1; i <= n; i++)
        	countTwoAndFive(i, twoandfive);
        return std::min(twoandfive[0], twoandfive[1]);
    }
};