#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        vector<string> str_arr = split(s);
        if(str_arr.empty()) return 0;
        else return str_arr[str_arr.size() - 1].size();
    }

    vector<string> split(string s){
    	vector<string> str_arr; // string array split by space
    	int pos = 0, len = s.size();
    	for(int i = 0; i < len; i++){
    		if(s[i] == ' ') {
    			string str = s.substr(pos, i - pos);
    			if(!str.empty()) str_arr.push_back(str);
    			pos = i + 1;
    		}
    	}

    	string str = s.substr(pos, len - pos);
    	if(!str.empty()) str_arr.push_back(str);
    	return str_arr;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str;
	while(getline(cin, str)){
		cout << s.lengthOfLastWord(str) << endl;
	}
	return 0;
}