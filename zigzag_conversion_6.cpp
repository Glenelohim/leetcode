#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		string res = "";

		if ((numRows < 2) || (s.length() <= 1))
			return s;
		for (int i = 0; i < numRows; i++)
		{
			int j = i;
			int flag = 1;
			
			while (j < s.length())
			{
				res += s[j];

				if (i == 0 || i == numRows - 1)
					j += 2 * numRows - 2;
				else
				{
					if (flag)
					{
						j += 2 * (numRows - i) - 2;
						flag = 0;
					}
					else
					{
						j += 2 * i;
						flag = 1;
					}
				} 
			}
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution a;
	string kk = a.convert("ABCDE", 4);
	cout << kk << endl;
	return 0;
}