#include <iostream>
#include <climits>
#include <cctype>
using namespace std;

class Solution
{
public:
	int myAtoi(string str){
		int pos = 0, len = str.size();
		bool sign = true;
		// skip the starting space
		for(pos = 0; pos < len && str[pos] == ' '; pos++);
		if(str[pos] == '+') {
			pos++;
			sign = true;
		}else if(str[pos] == '-'){
			pos++;
			sign = false;
		}

		long res = 0;
		while(isdigit(str[pos])){
			res = res * 10 + str[pos] - '0';
			pos++;
			if(sign && res > INT_MAX) return INT_MAX;
			else if(!sign && -res < INT_MIN) return INT_MIN;
		}
		return sign ? res : -res;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str;
	while(getline(cin, str)){
		cout << s.myAtoi(str) << endl;
	}
	return 0;
}