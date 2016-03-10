class Solution {
public:
	void dfs(vector<vector<int>>& res, vector<int>& candidates, vector<int>& temp, int target, int level)
	{
		if (target < 0)
		{
			return;
		}
		if (0 == target)
		{
			res.push_back(temp);
			return;
		}
		for (int i = level; i < candidates.size(); i++)
		{
			if (i > level && candidates[i] == candidates[i-1])
				continue;
			temp.push_back(candidates[i]);
			dfs(res, candidates, temp, target - candidates[i], i + 1);
			temp.pop_back();
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (!candidates.size())
        {
        	return res;
        }
        sort(candidates.begin(), candidates.end(), less<int>());
        vector<int> temp;
        dfs(res, candidates, temp, target, 0);
    }
};