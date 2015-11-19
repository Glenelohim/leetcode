class Solution {
public:
	//find the (begin, end) max money
	int rob_help(vector<int>& nums, int begin, int end)
	{
		int note[end - begin + 2];
		note[0] = 0;
		note[1] = nums[begin];
		for (int i = 2; i <= (end - begin + 1); i++)
			note[i] = std::max(note[i-1], note[i-2] + nums[begin+i-1]);
		return note[end - begin + 1];
	}
    int rob(vector<int>& nums) {
    	int nums_len = nums.size();
        if (nums_len == 0)
        	return 0;
        if (nums_len == 1)
        	return nums[0];
        int range_0_NminusOne = rob_help(nums, 0, nums_len - 2);
        int range_1_N = rob_help(nums, 1, nums_len - 1);
        return std::max(range_0_NminusOne, range_1_N);
    }
};

/*
M[k] -> the k-th house money
p[0] = 0 -> the max money can rob
p[1] = M[1]
p[i] = max(p[i-1], p[i-2]+M[i])

p[n] = max(p[0...n-1], p[1...n]); either no pick nums[0], or no pick nums[n]
*/