class Solution {
public:
	vector<string> str2vec(string str)
	{
		vector<string> res;
		int str_len = str.length();
		if (!str_len) return res;
		int pos = 0;
		while (pos < str_len)
		{
			if (str[pos] == ' ')
			{
				pos++;
				continue;
			}
			int i = pos + 1;
			for (; i < str_len; i++)
			{
				if (str[i] == ' ')
				{
					string temp = str.substr(pos, i - pos);
					res.push_back(temp);
					break;
				}
			}
			if (i == str_len)
			{
				string temp = str.substr(pos);
				res.push_back(temp);
				break;
			}
			pos = i;
		}
		return res;
	}

	//fuck the pattern may not begin with 'a'
    bool wordPattern(string pattern, string str) {
        int pattern_len = pattern.length();
        int str_len = str.length();
        if (!pattern_len || !str_len) return false;

        vector<string> str_string = str2vec(str);
        if (pattern_len != str_string.size()) return false;

        string str2pattern = "";
        str2pattern += pattern[0];

        map<string, char> m1;       
        m1[str_string[0]] = pattern[0];
        map<char, string> m2;
        m2[pattern[0]] = str_string[0];
        

        for (int i = 1; i < str_string.size(); i++)
        {
        	if (m1.find(str_string[i]) == m1.end() && m2.find(pattern[i]) == m2.end())
        	{
        		m1[str_string[i]] = pattern[i];
        		m2[pattern[i]] = str_string[i];
        		str2pattern += pattern[i];
        	}
        	else if(m1.find(str_string[i]) != m1.end() && m2.find(pattern[i]) != m2.end())
        		str2pattern += pattern[i];
        	else
        		return false;
        }
        return str2pattern == pattern;
    }
};