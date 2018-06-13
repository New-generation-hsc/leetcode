/**
Add two binary string
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string addBinary(string a, string b){
		int i = a.size() - 1, j = b.size() - 1, carry = 0;
		string str = "";
		while(i >= 0 || j >= 0 || carry > 0){
			int bit_a = i >= 0 ? a[i] - '0' : 0;
			int bit_b = j >= 0 ? b[j] - '0' : 0;
			int sum = bit_a ^ bit_b ^ carry;
			str = char(sum + '0') + str;
			carry = (bit_a & bit_b) | (carry & (bit_a ^ bit_b));
			i--;
			j--; 
		}

		return str;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	string a, b;
	while(cin >> a >> b){
		cout << s.addBinary(a, b) << endl;
	}
	return 0;
}