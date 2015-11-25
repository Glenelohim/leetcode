class Solution {
public:
	//fuck out using divideconquer
	//using a concise soluion from discuss
    int lengthOfLongestSubstring(string s) {
    	int len = s.length();
    	if (len <= 1) return len;

    	int start = 0, res = 0;
    	unordered_map<char, int> s_map;
    	for (int i = 0; i < len; i++)
    	{
    		if (s_map.find(s[i]) != s_map.end())
    		{
    			res = max(res, i - start);
    			start = max(start, s_map[s[i]] + 1);
    		}
    		s_map[s[i]] = i;
    	}
    	res = max(res, len - start);
    	return res;
    }
};