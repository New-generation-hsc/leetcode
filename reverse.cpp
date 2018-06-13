/**
* Given an signed number between -2^32 and 2^32-1
* try to reverse the number if the result overflow then return 0
*/
#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
	int reverse(int x){
		long res = 0;

		int tmp = x > 0 ? x : -x;
		while(tmp != 0){
			res = res * 10 + tmp % 10;
			tmp /= 10;
		}

		if(res > INT_MAX || res < INT_MIN) return 0;
		return x > 0 ? res : -res;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	int x;
	while(cin >> x){
		cout << "~x : " << s.reverse(x) << endl;
	}
	return 0;
}