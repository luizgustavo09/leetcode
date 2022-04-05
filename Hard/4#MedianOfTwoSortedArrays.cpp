class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int t = nums1.size() + nums2.size();
        vector<int> v(t);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
        if(t % 2)
            return v[t >> 1]/1.0;
        else
            return (v[t >> 1] + v[(t >> 1) - 1])/2.0;
    }
};
