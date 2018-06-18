#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        unordered_map<char, char> map = {{'{', '}'}, {'[', ']'}, {'(', ')'}};
        for(int i = 0; i < str.size(); i++){
        	char currChar = str[i];
        	if(currChar == '{' || currChar == '[' || currChar == '('){
        		s.push(currChar);
        	}else {
        		if(!s.empty() && currChar == map[s.top()]){
        			s.pop();
        		}else{
        			return false;
        		}
        	}
        }

        return s.empty();
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str;
	while(cin >> str) {
		cout << s.isValid(str) << endl;
	}
	return 0;
}
