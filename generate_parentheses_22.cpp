class Solution {
public:
	void helper(vector<string>& res, int left, int right, string str)
	{
		if (0==left && 0==right)
		{
			res.push_back(str);
			return;
		}

		if (left > 0)
		{
			helper(res, left-1, right, str+'(');
		}

		if (left < right)
		{
			helper(res, left, right-1, str+')');
		}
	}

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (0 == n)
        {
        	return res;
        }

        helper(res, n, n, "");

        return res;
    }
};