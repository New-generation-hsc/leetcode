#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	int len = strs.size();
    	if (len == 0) return "";

        for(int i = 0; i < strs[0].size(); i++){
            char c = strs[0][i];
            for(int j = 1; j < len; j++){
                if(i >= strs[j].size() || strs[j][i] != c){
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};

class CommonPrefix
{
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len == 0) return "";
        return binary_search(strs, 0, len - 1);
    }

private:
    string binary_search(vector<string>& strs, int low, int high){
        if(low == high) return strs[low];
        if(high - low == 1) {
            return commonPrefix(strs[low], strs[high]);
        }

        int mid = (low + high) >> 1;
        string left = binary_search(strs, low, mid);
        string right = binary_search(strs, mid + 1, high);
        return commonPrefix(left, right);
    }

    string commonPrefix(string str1, string str2){
        int len = min(str1.size(), str2.size());
        for(int i = 0; i < len; i++){
            if(str1[i] != str2[i]){
                return str1.substr(0, i);
            }
        }
        return str1.substr(0, len);
    }
};


int main(int argc, char const *argv[])
{
	CommonPrefix s;
    vector<string> strs = {"flower"};
    cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}