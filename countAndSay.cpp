#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    	if(n == 1) return "1";
    	string prev = countAndSay(n - 1); // the previous number say string

    	char ch = prev[0];
    	int cnt = 1;
    	string ans = "";
    	for(int i = 1; i < prev.size(); i++){
    		if(prev[i] == ch){
    			cnt++;
    		}else{
    			ans += to_string(cnt) + ch;
    			ch = prev[i];
    			cnt = 1;
    		}
    	}
    	ans += to_string(cnt) + ch;
    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int n;
	while(cin >> n){
		cout << s.countAndSay(n) << endl;
	}
	return 0;
}