#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int romanToInt(string s){
		int pos = 0, len = s.size();
		int res = 0;
		while(pos < len){
			int e = 0;
			if(s[pos] == 'I'){
				e = 1;
				pos++;
				if(pos < len && s[pos] == 'V'){
					e = 4;
					pos++;
				}else if(pos < len && s[pos] == 'X'){
					e = 9;
					pos++;
				}
			}else if(s[pos] == 'X'){
				e = 10;
				pos++;
				if(pos < len && s[pos] == 'V'){
					e = 40;
					pos++;
				}else if(pos < len && s[pos] == 'C'){
					e = 90;
					pos++;
				}
			}else if(s[pos] == 'C'){
				e = 100;
				pos++;
				if(pos < len && s[pos] == 'D'){
					e = 400;
					pos++;
				}else if(pos < len && s[pos] == 'M'){
					e = 900;
					pos++;
				}
			}else if(s[pos] == 'V'){
				e = 5;
				pos++;
			}else if(s[pos] == 'L'){
				e = 50;
				pos++;
			}else if(s[pos] == 'D'){
				e = 500;
				pos++;
			}else{
				e = 1000;
				pos++;
			}
			res += e;
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str;
	while (cin >> str){
		cout << s.romanToInt(str) << endl;
	}
	return 0;
}
