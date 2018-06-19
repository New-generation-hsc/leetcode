#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        unordered_map<char, string> map = {
        	{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        	{'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        	{'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> strs;
        for(auto ch : digits) strs.push_back(map[ch]);
        return depthSeach(strs, 0);
    }

    vector<string> depthSeach(vector<string> strs, int deep){
    	if(deep >= strs.size()) return {""};

    	vector<string> ans;

    	string first = strs[deep];
    	for(int i = 0; i < first.size(); i++){
    		char startChar = first[i];
    		vector<string> rest = depthSeach(strs, deep + 1);
    		for(auto e : rest){
    			ans.push_back(startChar + e);
    		}
    	}

    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str;
	while(cin >> str){
		vector<string> ans = s.letterCombinations(str);
		for(auto e : ans) cout << e << endl;
	}
	return 0;
}