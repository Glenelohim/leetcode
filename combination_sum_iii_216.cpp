class Solution {
public:
	void dfs(vector<vector<int>>& res, vector<int>& temp, int n, int k, int index)
	{
		if (k == 0 && n == 0)
		{
			res.push_back(temp);
			return;
		}
		else if (k == 0 || n == 0)
		{
			return;
		}
		for (int i = index; i <= 9; i++)
		{
			temp.push_back(i);
			dfs(res, temp, n - i, k - 1, i + 1);
			temp.pop_back();
		}
	}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (n < 1)
        {
        	return res;
        }
        vector<int> temp;
        dfs(res, temp, n, k, 1);
        return res;
    }
};