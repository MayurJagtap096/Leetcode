class Solution {
public:

    void merge(vector<int>& nums, int l, int mid, int r) {
        int s1 = mid-l+1;
        int s2 = r-mid;
        vector<int> arr1(s1);
        vector<int> arr2(s2);

        for(int i=0;i<s1;i++) {
            arr1[i] = nums[l+i];
        }
        for(int i=0;i<s2;i++) {
            arr2[i] = nums[mid+i+1];
        }   

        int i=0,j=0;
        while(i<s1 && j<s2) {
            if(arr1[i]<arr2[j]) {
                nums[l++] = arr1[i++];
            }
            else {
                nums[l++] = arr2[j++];
            }
        }
        while(i<s1) {
            nums[l++] = arr1[i++];
        }
        while(j<s2) {
            nums[l++] = arr2[j++];
        }
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if(l<r) {
            int mid = (l+r)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);
            merge(nums,l,mid,r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};