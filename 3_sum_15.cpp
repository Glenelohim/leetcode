class Solution {
public:
	//this awesome solution is from the discuss 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
        	return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
        	if ((i > 0) && (nums[i] == nums[i - 1]))
        		continue;
        	int left = i + 1;
        	int right = nums.size() - 1;
        	while (left < right)
        	{
        		int temp = nums[i] + nums[left] + nums[right];
        		if (temp == 0)
        		{
        			res.push_back(vector<int> {nums[i], nums[left], nums[right]});
        			while ((nums[left] == nums[left + 1]) && (left < right))
        				left++;
        			while ((nums[right] == nums[right - 1]) && (left < right))
        				right--;
        			left++;
        			right--;
        		}
        		else if (temp > 0)
        		{
        			right--;
        		}
        		else
        		{
        			left++;
        		}
        	}
        }
        return res;
    }
};