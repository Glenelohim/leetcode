class Solution {
public:
	//dp solution from discuss
    int maxProduct(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size == 1)
        	return nums[0];
        vector<int> currentMax(nums_size, 0);
        vector<int> currentMin(nums_size, 0);
        int res = nums[0];
        currentMin[0] = nums[0];
        currentMax[0] = nums[0];

        for (int i = 1; i < nums_size; i++)
        {
        	if (nums[i] == 0)
        	{
        		currentMax[i] = 0;
        		currentMin[i] = 0;
        	}
        	else if (nums[i] > 0)
        	{
        		currentMax[i] = max(nums[i], currentMax[i-1] * nums[i]);
        		currentMin[i] = min(nums[i], currentMin[i-1] * nums[i]);
        	}
        	else
        	{
        		currentMax[i] = max(nums[i], currentMin[i-1] * nums[i]);
        		currentMin[i] = min(nums[i], currentMax[i-1] * nums[i]);
        	}
        	res = max(res, currentMax[i]);
        }
        return res;
    }
};