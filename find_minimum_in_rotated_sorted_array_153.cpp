class Solution {
public:
	int findmin_help(vector<int>& nums, int low, int high)
	{
		int mid = (low + high) / 2;
		if (nums[low] < nums[high] || low >= high)
		{
			return nums[low];
		}
		else if (nums[mid] > nums[high])
		{
			return findmin_help(nums, mid + 1, high);
		}
		else
		{
			return findmin_help(nums, low, mid);
		}
	}
    int findMin(vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size)
        {
        	return 0;
        }
        return findmin_help(nums, 0, nums_size - 1);
    }
};