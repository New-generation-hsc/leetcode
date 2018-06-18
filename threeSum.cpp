#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> ans;
    	int len = nums.size();
    	if(len < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; i++){
        	if(i > 0 && nums[i] == nums[i - 1]) continue;
        	int low = i + 1;
        	int high = len - 1;
        	while(low < high){
        		if(nums[i] + nums[low] + nums[high] == 0){
        			vector<int> res = {nums[i], nums[low], nums[high]};
        			ans.push_back(res);
        			while(low < high && nums[low] == nums[low + 1]) low++;
        			while(low < high && nums[high] == nums[high - 1]) high--;
        			low++; high--;
        		}else if (nums[i] + nums[low] + nums[high] > 0){
        			high--;
        		}else{
        			low++;
        		}
        	}
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {0, 0, 0, 0};
	auto ans = s.threeSum(nums);
	for(auto arr : ans){
		for(auto e : arr){
			cout << e << " ";
		}
		cout<<endl;
	}
	return 0;
}