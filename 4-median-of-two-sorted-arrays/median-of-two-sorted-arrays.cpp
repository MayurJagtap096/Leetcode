class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        for(int i:nums1) merge.push_back(i);
        for(int i:nums2) merge.push_back(i);
        sort(merge.begin(),merge.end());
        if(merge.size()%2==0){
            int m = merge[merge.size()/2];
            int n = merge[merge.size()/2 - 1];
            return (static_cast<double>(m)+static_cast<double>(n))/2.0;
        }
        return static_cast<double>(merge[merge.size()/2]);
    }
};