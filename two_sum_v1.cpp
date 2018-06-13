#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        // map to keep track of numbers and indices
        map<int, int> treeMap;

        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            // if complement exists, find out index and return
            if(treeMap.find(complement) != treeMap.end()){
                vector<int> result;
                result.push_back(treeMap[complement]);
                result.push_back(i);
                return result;
            }else{
                // if not exists, keep the record index
                treeMap[nums[i]] = i;
            }
        }
    }
};

int main(){
    int input[4] = {2, 7, 11, 15};
    vector<int> nums(input, input + 4);
    int target = 9;
    
    Solution s;
    vector<int> result = s.twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
