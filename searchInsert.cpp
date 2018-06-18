#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if(nums.size() == 0) return 0;
        return binary_search(nums, target, 0, nums.size() - 1);
    }

    int binary_search(vector<int>& nums, int target, int low, int high){
    	if(low > high) return low;
    	int mid = (low + high) >> 1;
    	if(nums[mid] == target) return mid;
    	else if(nums[mid] > target) return binary_search(nums, target, low, mid - 1);
    	else return binary_search(nums, target, mid + 1, high);
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {1, 3, 5, 6};
	cout << s.searchInsert(nums, 7) << endl;
	return 0;
}