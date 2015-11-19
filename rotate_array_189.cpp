class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	if (!nums.size())
    		return;
        while (k > 0)
        {
        	int temp = nums.back();
        	nums.pop_back();
        	nums.insert(nums.begin(), temp);
        	k--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int numLen = nums.size();
        if (!numLen)
            return;
        vector<int> temp = nums;
        for (int i = 0; i < numLen; i++)
            nums[i] = temp[(i - (k % numLen) + numLen) % numLen];
    }

    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        if(k==0 || nums.size()==0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};