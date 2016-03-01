class Solution {
public:
	bool binarySearch(vector<int>& nums, int target, int low, int high)
	{
		if (low > high)
			return false;
		int mid = (low + high) / 2;
		if (target == nums[mid])
			return true;
		int mid_right = mid+1, mid_left = mid-1;
		while (mid_right < high && nums[mid_right] == nums[mid])
			mid_right++;
		while (mid_left > low && nums[mid_left] == nums[mid])
			mid_left--;
		if (target > nums[mid])
			return binarySearch(nums, target, mid_right, high);
		return binarySearch(nums, target, low, mid_left);
	}

    bool search(vector<int>& nums, int target) {
        int nums_size = nums.size();
        if (!nums_size)
        	return false;
        int i = 0, j = nums_size-1;
        for (; i < j; i++, j--)
        {
        	if (nums[i] < nums[j])
        		break;
        	if (nums[i] == target || nums[j] == target)
        		return true;
        }
        return binarySearch(nums, target, i, j);
    }
};