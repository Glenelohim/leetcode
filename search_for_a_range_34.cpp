class Solution {
public:
	void binarySearch(vector<int>& nums, vector<int>& res, int target, int low, int high)
	{
		if (low > high)
		{
			res[0] = -1;
			res[1] = -1;
			return;
		}
		int mid = (low + high) / 2;
		int mid_left = mid-1, mid_right = mid+1;
		while (mid_left >= low && nums[mid_left] == nums[mid])
			mid_left--;
		while (mid_right <= high && nums[mid_right] == nums[mid])
			mid_right++;
		if (target == nums[mid])
		{
			res[0] = mid_left+1;
			res[1] = mid_right-1;
			return;
		}
		if (target > nums[mid])
			binarySearch(nums, res, target, mid_right, high);
		else
			binarySearch(nums, res, target, low, mid_left);
	}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        int nums_size = nums.size();
        if (!nums_size)
        	return res;
        binarySearch(nums, res, target, 0, nums_size-1);
        return res;
    }
};