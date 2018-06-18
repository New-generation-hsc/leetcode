#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> map  = {
        	{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"},
        	{40, "40"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"},
        	{500, "D"}, {900, "CM"}, {1000, "M"}
        };
        string ans = "";
        int level = 1;
        while(num != 0){
        	int x = num % 10;
        	ans = extendToRoman(x * level, level, map) + ans;
        	level *= 10;
        	num /= 10;
        }

        return ans;
    }

    string extendToRoman(int num, int level, unordered_map<int, string>& map){
    	if(map.find(num) != map.end()) return map[num];
    	int val = level * 5;
    	string ans = "";
    	if(num >= val) {
    		num -= val;
    		ans += map[val];	
    	}

    	while(num != 0){
    		num -= level;
    		ans += map[level];
    	}

    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int num;
	while(cin >> num){
		cout << s.intToRoman(num) << endl;
	}
	return 0;
}