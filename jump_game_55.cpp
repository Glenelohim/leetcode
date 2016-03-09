class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size)
        	return false;
        if (1 == nums_size)
        	return true;
        vector<int> dp(nums_size, 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums_size; i++)
        {
        	if (i > dp[i-1])
        	{
        		return false;
        	}
        	else
        	{
        		dp[i] = max(i + nums[i], dp[i-1]);
        		if (dp[i] >= nums_size-1)
        		{
        			return true;
        		}
        	}
        }
        return true;
    }
};