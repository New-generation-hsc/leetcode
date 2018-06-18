#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int i = digits.size() - 1, carry = 0;
        digits[i] += 1;
        while(i >= 0 || carry){
        	int num = (digits[i] + carry) % 10;
        	carry = (digits[i] + carry) / 10;
        	ans.insert(ans.begin(), num);
        	i--;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> digits = {9};
	vector<int> nums = s.plusOne(digits);
	for(auto e : nums){
		cout << e << endl;
	}
	return 0;
}