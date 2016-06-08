class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int len1 = nums1.size();
        int len2 = nums2.size();

        if ((0 == len1) || (0 == len2))
        {
        	return res;
        }
        if (len1 < len2)
        {
        	return intersect(nums2, nums1);
        }

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int index1 = 0, index2 = 0;
        while ((index2 < len2) && (index1 < len1))
        {
        	if (nums1[index1] == nums2[index2])
        	{
        		res.push_back(nums1[index1]);
        		index1++;
        		index2++;
        	}
        	else if (nums1[index1] > nums2[index2])
        	{
        		index2++;
        	}
        	else
        	{
        		index1++;
        	}
        }

        return res;
    }
};