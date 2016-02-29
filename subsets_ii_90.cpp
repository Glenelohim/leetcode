class Solution {
public:
	void subsetsWithDup_help(vector<int>&nums, vector<vector<int> >& res, vector<int>& vec, int n)
	{
		int nums_size = nums.size();
		if (n >= nums_size)
			return;
		for (int i = n; i < nums_size; i++)
		{
			if ((i == n) || (nums[i] != nums[i-1]))
			{
				vec.push_back(nums[i]);
				res.push_back(vec);
				subsetsWithDup_help(nums, res, vec, i+1);
				vec.pop_back();
			}
		}
	}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        int nums_size = nums.size();
        if (!nums_size)
        	return res;
        std::sort(nums.begin(), nums.end(), less<int>());
        vector<int> temp;
        res.push_back(temp);
       	subsetsWithDup_help(nums, res, temp, 0);
        return res;
    }
};