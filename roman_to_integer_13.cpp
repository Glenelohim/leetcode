#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		int index = 0;
		int C_nums_before_ = 0;
		int X_nums_before_ = 0;
		int I_nums_before_ = 0;
		int res = 0;
		for (; index < s.length(); index++)
		{
			switch (s[index])
			{
			case 'M':
				if (C_nums_before_)
					res += 900;
				else
					res += 1000;
				C_nums_before_ = 0;
				break;
			case 'D':
				if (C_nums_before_)
					res += 400;
				else
					res += 500;
				C_nums_before_ = 0;
				break;
			case 'C':
				if (!X_nums_before_)
				{
					C_nums_before_ ++;
					break;
				}
				else
				{
					res += 90;
					X_nums_before_ = 0;
					break;
				}
			case 'L':
				if (X_nums_before_)
					res += 40;
				else
					res += 50;
				X_nums_before_ = 0;
				break;
			case 'X':
				if (!I_nums_before_)
				{
					X_nums_before_ ++;
					break;
				}
				else
				{
					res += 9;
					I_nums_before_ = 0;
					break;
				}
			case 'V':
				if (I_nums_before_)
					res += 4;
				else
					res += 5;
				I_nums_before_ = 0;
				break;
			case 'I':
				I_nums_before_ ++;
				break;
			}
		}
		res = res + 100 * C_nums_before_ + 10 * X_nums_before_ + I_nums_before_;
		return res;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}