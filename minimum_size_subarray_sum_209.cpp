class Solution {
public:
	//O(n) solution from the discuss
	int minSubArrayLen(int s, vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size || (nums_size == 1 && nums[0] != s))
        	return 0;
        int begin = 0, end = 0, min_len = nums_size+1, sum = 0;
        for (; end < nums_size;)
        {
        	sum += nums[end];
        	end++;
        	while (sum >= s)
        	{
        		if ((end - begin) < min_len)
        			min_len = end - begin;
        		sum -= nums[begin];
        		begin++;
        	}
        }
        if (min_len == nums_size+1)
        	return 0;
        return min_len;
    }

	//bad O(nlogn) solution...
	int minSubArrayLen_help(vector<int>& nums, int s, int low, int high)
	{
		if (low > high)
			return 0;
		int mid = (low + high) / 2, mid_left = mid-1, mid_right=mid+1;
		int sum = nums[mid], count = 1;
		while (sum < s && mid_left >= low && mid_right <= high)
		{
			if (nums[mid_left] > nums[mid_right])
			{
				sum += nums[mid_left];
				mid_left--;
			}
			else
			{
				sum += nums[mid_right];
				mid_right++;
			}
			count++;
		}
		if (sum >= s)
		{
			int left = minSubArrayLen_help(nums, s, low, mid-1);
			int right = minSubArrayLen_help(nums, s, mid+1, high);
			if (left && right)
				return std::min(count, std::min(left, right));
			else if (left)
				return std::min(count, left);
			else if (right)
				return std::min(count, right);
			else
				return count;
		}
		if (mid_left < low)
		{
			while (mid_right <= high)
			{
				sum += nums[mid_right];
				count++;
				if (sum >= s)
				{
					int left = minSubArrayLen_help(nums, s, low, mid-1);
					int right = minSubArrayLen_help(nums, s, mid+1, high);
					if (left && right)
						return std::min(count, std::min(left, right));
					else if (left)
						return std::min(count, left);
					else if (right)
						return std::min(count, right);
					else
						return count;
				}
				mid_right++;
			}
			return 0;
		}
		else
		{
			while (mid_left >= low)
			{
				sum += nums[mid_left];
				count++;
				if (sum >= s)
				{
					int left = minSubArrayLen_help(nums, s, low, mid-1);
					int right = minSubArrayLen_help(nums, s, mid+1, high);
					if (left && right)
						return std::min(count, std::min(left, right));
					else if (left)
						return std::min(count, left);
					else if (right)
						return std::min(count, right);
					return count;
				}
				mid_left--;
			}
			return 0;
		}		
	}

    int minSubArrayLen(int s, vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size || (nums_size == 1 && nums[0] != s))
        	return 0;
        return minSubArrayLen_help(nums, s, 0, nums_size-1);
    }
};