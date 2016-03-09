class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size)
        	return 1;
        unordered_set<int> u_set;
        for (int i : nums)
        {
        	u_set.insert(i);
        	/* for unordered_set.insert()
			Complexity:
			Single element insertions:
			Average case: constant.
			Worst case: linear in container size.
			*/
        }
        int res = 1;
        while (u_set.find(res) != u_set.end())
        {
        	res++;
        }
        return res;
    }
};
