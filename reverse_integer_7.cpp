#include <iostream>
using namespace std;

class Solution
{
public:
	int reverse(int x)
	{
		long long res = 0;
		const int max = 0x7fffffff;
		const int min = 0x80000000;
		if (x == 0)
			return 0;
		if (x > 0)
		{
			while (x)
			{
				res = res * 10 + x % 10;
				if (res > max || res < min)
					return 0;
				x = x / 10;
			}
		}
		else
		{
			x = -x;
			while (x)
			{
				res = res * 10 + x % 10;
				if (res > max || res < min)
					return 0;
				x = x / 10;
			}
			res = -res;
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution a;
	cout << a.reverse(1534236469) << endl;
	return 0;
}