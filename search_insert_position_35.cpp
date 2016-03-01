class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int nums_size = nums.size();
        if (!nums_size)
        	return 0;
        int i = 0;
        for (; i < nums_size; i++)
        {
        	if (target == nums[i])
        		return i;
        	else if (target > nums[i])
        		continue;
        	else
        		break;
        }
        return i;
    }
};