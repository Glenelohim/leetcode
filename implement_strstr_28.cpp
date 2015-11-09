class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		int haystack_len = haystack.length();
		int needle_len = needle.length();

		if (!needle_len)
			return 0;
		if (!haystack_len || (haystack_len < needle_len))
			return -1;

		int is_strstr = 0;
		int is_equal = 1;
		int i = 0;
		for (; i <= (haystack_len - needle_len); i++)
		{
			is_equal = 1;
			if (haystack[i] == needle[0])
			{
				for (int j = 1; j < needle_len; j++)
				{
					if (haystack[i + j] != needle[j])
					{
						is_equal = 0;
						break;
					}
				}
				if (is_equal)
					is_strstr = 1;
			}
			if (is_strstr)
				return i;
		}
		return -1;
	}
};