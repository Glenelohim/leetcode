#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int myAtoi(string str)
	{
		const int MAX = 0x7fffffff;
		const int MIN = 0x80000000;
		long long res = 0;
		int flag_blank = 0;
		int flag_is_neg = 0;
		int temp = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ' && !flag_blank)
				continue;
			if (str[i] == '-' && !flag_is_neg && !flag_blank)
			{
				flag_blank = 1;
				flag_is_neg = 1;
				continue;
			}
			if (str[i] == '+' && !flag_is_neg && !flag_blank)
			{
				flag_blank = 1;
				continue;
			}
			if (str[i] >= '0' && str[i] <= '9')
			{
				temp = str[i] - '0';
				res = res * 10 + temp;
				if (res > MAX)
				{
					if (flag_is_neg)
						return MIN;
					else
						return MAX;
				}
				flag_blank = 1;
			}
			else
				break;
		}
		if (flag_is_neg)
			res = -res;
		return res;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution a;
	string s;
	while(1)
	{
		cin >> s;
		cout << a.myAtoi(s) << endl;
	} 
	return 0;
}