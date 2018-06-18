#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int len = nums.size();
    	for(int i = 0; i < len;){
    		if(nums[i] == val){
    			nums[i] = nums[len - 1];
    			len--;
    		}else{
    			i++;
    		}
    	}
    	return len;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {2};
	cout << "len: " << s.removeElement(nums, 2) << endl;
	for(auto e : nums){
		cout << e << endl;
	}
	return 0;
}