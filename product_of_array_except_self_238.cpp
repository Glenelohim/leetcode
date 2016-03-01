class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int nums_size = nums.size();
        if (!nums_size)
        	return res;
        long long product = 1;
        int zero_nums = 0;
        res = nums;
        for (int i = 0; i < nums_size; i++)
        {
        	if (nums[i] == 0)
        		zero_nums++;
        	else
        		product *= nums[i];
        }
        if (zero_nums > 1)
        {
        	for (int i = 0; i < nums_size; i++)
        		res[i] = 0;
        }
        else if (zero_nums == 1)
        {
        	for (int i = 0; i < nums_size; i++)
        	{
        		if (nums[i] == 0)
        			res[i] = product;
        		else
        			res[i] = 0;
        	}
        }
        else
        {
	        for (int i = 0; i < nums_size; i++)
	        {
	        	res[i] = product / nums[i];
	        }
    	}
        return res;
    }
};