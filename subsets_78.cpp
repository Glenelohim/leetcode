class Solution {
public:
	//Memory Limit Exceeded..oh no..
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        res.push_back(vector<int>());
        int nums_size = nums.size();
        if (!nums_size)
        	return res;
        vector<int> nums_cp = nums;
        std::sort(nums_cp.begin(), nums_cp.end(), less<int>());
        for (int i = 0; i < nums_size; i++)
        {
        	int res_size = res.size();
        	for (int j = 0; j < res_size; j++)
        	{
        		vector<int> temp = res[j];
				temp.push_back(nums_cp[i]);
				res.push_back(temp);
        	}
        }
		return res;
    }


    //using recursion
    void subsets_help(vector<int>& nums, vector<int> vec, vector<vector<int> >& res, int n)
    {
    	if (n == nums.size())
    	{
    		std::sort(vec.begin(), vec.end(), less<int>());
    		res.push_back(vec);
    		return;
    	}
    	//nums[n] is not in the vec
    	subsets_help(nums, vec, res, n+1);
    	//let nums[n] in the vec
    	vec.push_back(nums[n]);
    	subsets_help(nums, vec, res, n+1);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
    	vector<vector<int> > res;
    	int nums_size = nums.size();
    	if (!nums_size)
    		return res;
    	vector<int> vec;
    	subsets_help(nums, vec, res, 0);
    }
};