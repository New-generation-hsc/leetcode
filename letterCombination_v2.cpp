#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	const vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
    	vector<string> strs;
    	for(auto e : digits) strs.push_back(map[e - '0']);
    	vector<string> ans = {};
    	string path = "";
    	backtraceSearch(strs, 0, path, ans);
    	return ans;
    }

    void backtraceSearch(vector<string>& strs, int deep, string& path, vector<string>& ans){
    	if(deep == strs.size()) {
    		ans.push_back(path);
    		return;
    	}

    	string s = strs[deep];
    	for(int i = 0; i < s.size(); i++){
    		path.push_back(s[i]);
    		backtraceSearch(strs, deep + 1, path, ans);
    		path.pop_back();
    	}
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