class Solution {
public:
	void combinationSum_dfs(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& temp, int index)
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
		for (int i = index; i < candidates.size(); i++)
		{
			temp.push_back(candidates[i]);
			combinationSum_dfs(res, candidates, target - candidates[i], temp, i);
			temp.pop_back();
		}
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int size = candidates.size();
        vector<vector<int>> res;
        if (!size)
        {
        	return res;
        }
        sort(candidates.begin(), candidates.end(), less<int>());

        vector<int> temp;
        combinationSum_dfs(res, candidates, target, temp, 0);
        return res;
    }
};