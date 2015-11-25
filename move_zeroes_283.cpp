class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
        	return;
        for (int i = 0; i < len - 1; i ++)
        {
        	if (nums[i] == 0)
        	{
        		int temp_index = i + 1;
        		while (temp_index < len)
        		{
        			if (nums[temp_index])
        				break;
        			temp_index++;
        		}
        		if (temp_index >= len)
        			return;
        		std::swap(nums[i], nums[temp_index]);  //overflow be careful
        		if (temp_index == len - 1)
        			return;
        	}
        }
    }
};