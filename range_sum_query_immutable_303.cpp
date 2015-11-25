class NumArray {
public:
	//using dp
	vector<int> sums;
    NumArray(vector<int> &nums) {
    	sums.push_back(0);
        for (int i = 0; i < nums.size(); i++)
        	sums.push_back(sums[i] + nums[i]);
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);