class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size <= 1)
        	return nums_size;
        int mirror = nums[0];
        int i = 1, j = 1, count = 0;
        
        while (i < nums_size)
        {
        	while (i < nums_size && nums[i] == nums[i-1])
        	{
        		i++;
        		count++;
        	}
        	if (count >= 1)
        	{
        		nums[j++] = nums[i-1];
        		count = 0;
        	}
        	else
        	{
        		nums[j++] = nums[i++];
        	}
        }
        return j;
    }
};