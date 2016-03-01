class Solution {
public:
	int search(vector<int>& nums, int target) {
        int nums_size = nums.size();
        if (!nums_size)
        	return -1;
        for (int i = 0; i < nums_size; i++)
        {
        	if (target == nums[i])
        		return i;
        }
        return -1;
    }
	//return the index that it should be
    int search(vector<int>& nums, int target) {
        int nums_size = nums.size();
        if (!nums_size)
        	return 0;
        int index = 0;
        for (; index < nums_size; index++)
        {
        	if (nums[index] == target)
        		return index;
        	if (index == nums_size-1)
        		return nums_size;
        	if (target > nums[index])
        	{
        		if (target < nums[index+1] || nums[index] > nums[index+1])
        			return index+1;
        	}
        }
        return 0;
    }
};