#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int sum = 0;
        while(low < high){
        	sum = max(sum, min(height[low], height[high]) * (high - low));
        	if(height[low] <= height[high]){
        		low++;
        	}else{
        		high--;
        	}
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	cout << s.maxArea(nums) << endl;
	return 0;
}