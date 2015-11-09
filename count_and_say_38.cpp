class Solution {
public:
	string generate_nth_sequence(string s)
	{
		if (s.length() == 1)
			return "11";
		int count = 1;
		char mir_bit = s[0];
		string res = "";

		for (int i = 1; i < s.length(); i ++)
		{
			if (mir_bit == s[i])
				count ++;
			else
			{
				res += count + '0';
				res += mir_bit;
				mir_bit = s[i];
				count = 1;
			}
		}

		res += count + '0';
		res += mir_bit;
		return res;
	}
    string countAndSay(int n) {
        if (n <= 1)
        	return "1";
        string res = "1";
        int i = 1;
        while (i < n)
        {
        	res = generate_nth_sequence(res);
        	i ++;
        }
        return res;
    }
};