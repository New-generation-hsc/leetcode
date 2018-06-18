#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
        	sum = max(sum + nums[i], nums[i]);
        	if(sum > max_sum){
        		max_sum = sum;
        	}
        }
        return max_sum;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << s.maxSubArray(nums) << endl;
	return 0;
}