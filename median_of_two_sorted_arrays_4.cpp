class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (!len1 && !len2)	return 0;
        if (len1 < len2) return findMedianSortedArrays(nums2, nums1);
        if (!len2) return len1%2 ? nums1[len1/2] : (nums1[len1/2]+nums1[len1/2+1]) / 2;

        int mid = (len1 + len2) / 2;

    }
};