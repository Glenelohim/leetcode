class Solution {
public:
    int jump(vector<int>& nums) {
        int nums_size = nums.size();
        if (1 == nums_size)
        	return 0;
        int res = 1, begin = 1, end = nums[0], edge = nums[0];
        while (edge < nums_size-1)
        {
        	res++;
        	for (int i = begin; i <= end; i++)
        	{
        		edge = max(edge, nums[i] + i);
        	}
        	begin = end + 1;
        	end = edge;
        }
        return res;
    }
};