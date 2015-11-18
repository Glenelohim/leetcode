class Solution {
public:
    int titleToNumber(string s) {
        int s_len = s.length();
        if (!s_len)
        	return 0;
        int res = 0;
        for (int i = 0; i < s_len; i++)
        {
        	int j = s_len - i - 1;
        	int temp = 1;
        	while (j > 0)
        	{
        		temp *= 26;
        		j--;
        	}
        	res += (s[i] - 'A' + 1) * temp;
        }
        return res;
    }
};