class Solution {
public:
    string reverseVowels(string s) {
        string res = "";
        int len = s.size();
        if (0 == len) return res;

        string vowels = "";
        for (int i=0; i<len; i++)
        {
        	if ('a'==s[i] || 'e'==s[i] || 'i'==s[i] || 'o'==s[i] || 'u'==s[i]
        	 || 'A'==s[i] || 'E'==s[i] || 'I'==s[i] || 'O'==s[i] || 'U'==s[i] )
        		vowels += s[i];
        }

        int vowels_len = vowels.size();
        if (0 == vowels_len)  return s;

        for (int i=0, j=vowels_len-1; i<len; i++)
        {
        	if ('a'==s[i] || 'e'==s[i] || 'i'==s[i] || 'o'==s[i] || 'u'==s[i]
        	 || 'A'==s[i] || 'E'==s[i] || 'I'==s[i] || 'O'==s[i] || 'U'==s[i] )
        	{
        		res += vowels[j--];
        	}
        	else
        	{
        		res += s[i];
        	}
        }
        return res;
    }
};