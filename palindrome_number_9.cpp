#include <iostream>
using namespace std;

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0)
			return false;
		if (x <= 9)
			return true;
		int top_digit = 1;
		while (top_digit <= (x / 10))
			top_digit *= 10;
		while (x)
		{
			if ((x / top_digit) != (x % 10))
				return false;
			x = (x % top_digit) / 10; //cut the max_dig & min_dig 
			top_digit /= 100;
		}
		return true;

	}

	bool isPalindrome_2(int x)
	{//cheat the complier
    	int max = x;
        int min = 0;
        while(max >0)
        {
            min *= 10;
            min+= max %10;
            max /=10;
        }
        return min==x;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}