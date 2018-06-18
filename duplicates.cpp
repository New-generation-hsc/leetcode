#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size() == 0) return 0;
        int index = 0;
        for(int i = 1; i < nums.size(); i++){
        	if(nums[i] != nums[index]){
        		nums[++index] = nums[i];
        	}
        }
        return index + 1;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {0};
	cout << "len: " << s.removeDuplicates(nums) << endl;
	for(auto e : nums){
		cout << e << endl;
	}
	return 0;
}