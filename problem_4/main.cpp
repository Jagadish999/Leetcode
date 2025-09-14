#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);


int main() {
    vector<int> nums_1 {1, 2};
    vector<int> nums_2 {3, 4};

    double median = findMedianSortedArrays(nums_1, nums_2);

    return 0;
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged_vect = nums1;

    merged_vect.insert(merged_vect.end(), nums2.begin(), nums2.end());
    sort(merged_vect.begin(), merged_vect.end());

    if (merged_vect.size() % 2 != 0) {
        int mid_idx = merged_vect.size() / 2;
        return merged_vect[mid_idx];
    }
    else {
        int mid_sec_idx = merged_vect.size() / 2;
        int mid_first_idx = merged_vect.size() / 2 - 1;

        return (merged_vect[mid_first_idx] + merged_vect[mid_sec_idx]) / 2.0;
    }
}

