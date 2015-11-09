class Solution {
public:
    int lengthOfLastWord(string s) {
        int s_len = s.length();
        if (!s_len)
        	return 0;
        int res = 0;
        int len = 0;
        for (int i = 0; i < s_len; i++)
        {
        	if (s[i] == ' ')
        	{
        		if (len)
        			res = len;
        		len = 0;
        	}
        	else
        		len ++;
        }
        if (len)
            res = len;
        return res;
    }
};

//another Solution
int lengthOfLastWord(string s) {
    int l = s.size()-1, count = 0;
    while (l>=0 && isspace(s[l]))
        l--;
    while (l>=0 && isalpha(s[l])) {
        count++;
        l--;
    }
    return count;
}