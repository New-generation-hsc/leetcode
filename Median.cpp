#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if((m +n) & 0x1){
        	return (double)findKSmallest(nums1, 0, nums2, 0, (m + n + 2) / 2);
        }else{
            return (double)(findKSmallest(nums1, 0, nums2, 0, (m + n) / 2) + findKSmallest(nums1, 0, nums2, 0, (m + n + 2) / 2 )) / 2.0;
        }
    }

    int findKSmallest(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k){

        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 - start1 > len2 - start2) return findKSmallest(nums2, start2, nums1, start1, k);
        if(start1 >= len1) return nums2[start2 + k - 1];

    	if(k == 1) return min(nums1[start1], nums2[start2]);

    	int midden = min(k / 2, len1 - start1);
    	int rest = k - midden;
    	if(nums1[start1 + midden - 1] <= nums2[start2 + rest - 1])
    		return findKSmallest(nums1, start1 + midden, nums2, start2, rest);
    	else
    		return findKSmallest(nums1, start1, nums2, start2 + rest, midden);
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums1 = {100001};
	vector<int> nums2 = {100000};
	cout << s.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}