class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size || 1 == nums_size)
        {
        	return 0;
        }
        if (nums[0] > nums[1])
        {
        	return 0;
        }
        else if (nums[nums_size-1] > nums[nums_size-2])
        {
        	return nums_size-1;
        }
        else
        {
        	for (int i = 1; i < nums_size-1; i++)
        	{
        		if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
        		{
        			return i;
        		}
        	}
        }
    }
};