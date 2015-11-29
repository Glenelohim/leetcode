class Solution {
public:
	string manacher_algorithm(string s)
	{
		string ss = "$#";
		//initial ss to "$#a1#a2#...an#"
		for (int i = 0; i < s.length(); i ++)
		{
			ss += s[i];
			ss += "#";
		}

		int* p = new int[ss.length() + 1];
		int max = 0, id = 0;  //max is the most right boundary before i, id is its index
		int maxpi = 0, maxpi_index = 0;
		memset(p, 0, sizeof(p));
		//initial p[i]
		for (int i = 1; i < (ss.length()+1); i++)
		{
			if (max > i)
				p[i] = min(p[2*id-i], max-i);
			else
				p[i] = 1;
			while (ss[i - p[i]] == ss[i + p[i]])
				p[i]++;

			if (i + p[i] > max)
			{
				max = i + p[i];
				id = i;
			}
			if (p[i] > maxpi)  //get the biggest p[i]
			{
				maxpi = p[i];
				maxpi_index = i;
			}
		}
		
		string res = "";
		for (int i = maxpi_index - maxpi + 1; i < maxpi_index + maxpi; i++)
			if (ss[i] != '#')
				res += ss[i];

		delete p;
		return res;
	}

    string longestPalindrome(string s) {
        int s_len = s.length();
        if (s_len <= 1) return s;
        return manacher_algorithm(s);
    }
};