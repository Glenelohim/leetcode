class Solution {
public:
	int findmin_help(vector<int>& nums, int low, int high)
	{
		if (low >= high || nums[low] < nums[high])
		{
			return nums[low];
		}
		int mid = (low + high) / 2;
		if (nums[mid] > nums[high])
		{
			return findmin_help(nums, mid + 1, high);
		}
		else if (nums[low] > nums[mid])
		{
			return findmin_help(nums, low, mid);
		}
		else
		{
			return findmin_help(nums, low, high-1);
		}
	}

    int findMin(vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size)
        	return 0;
        return findmin_help(nums, 0, nums_size - 1);
    }
};