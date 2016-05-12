class Solution {
public:
    string reverseString(string s) {
        string res = "";
        int len = s.length();

        if (0 == len)
        {
        	return res;
        }

        for (int i=len-1; i>=0; i--)
        {
        	res += s[i];
        }
        return res;
    }
};