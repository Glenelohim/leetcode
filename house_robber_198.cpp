class Solution {
public:
    int rob(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen == 0)
        	return 0;
        if (numsLen == 1)
        	return nums[0];
        vector<int> p(numsLen + 1, 0);
        p[0] = 0;
        p[1] = nums[0];

        for (int i = 2; i <= numsLen; i++)
        {
        	p[i] = std::max(p[i-1], p[i-2] + nums[i-1]);
        }
        return p[numsLen];
    }
};

/*
M[k] -> the k-th house money
p[0] = 0 -> the max money can rob
p[1] = M[1]
p[n] = max(p[n-1], p[n-2]+M[n])
*/

//another awesome Solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int it1 = 0, it2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            it1 = max(it1 + nums[i], it2);
            swap(it1, it2);
        }
        return it2;
    }
};