class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if (!strs.size())
			return "";
		string prefixStr = strs[0];
		int prefixLen = 0;
		int i = 1;
		int j = 0;

		for (; i < strs.size(); i++)
		{
			if (!prefixStr.length() || !strs[i].length())
				return "";
			if (prefixStr.length() <= strs[i].length())
				prefixLen = prefixStr.length();
			else
				prefixLen = strs[i].length();
			for (j = 0; j < prefixLen; j++)
			{
				if (prefixStr[j] != strs[i][j])
					break;
			}
			prefixStr = prefixStr.substr(0, j);
		}
		return prefixStr;
	}
};
