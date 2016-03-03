class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size == 1)
        	return nums[0];
        int max_sum = nums[0];
        int temp_sum = 0;
        for (int i = 0; i < nums_size; i++)
        {
        	temp_sum += nums[i];
        	if (temp_sum > max_sum)
        		max_sum = temp_sum;
        	if (temp_sum < 0)
        		temp_sum = 0;
        }
        return max_sum;
    }
};