#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int res = 0, tmp = x;
        while(tmp != 0){
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        return res == x;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int x;
	while(cin >> x){
		cout << s.isPalindrome(x) << endl;
	}
	return 0;
}