#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay_len = haystack.size(), len = needle.size();
        if(len == 0) return 0;
        int next[len];
        getNext(needle, next);
        int res = kmp_match(haystack, needle, next);
        return res;
    }

    int kmp_match(string haystack, string needle, int next[]){
    	int i = 0, j = 0;
    	int hay_len = haystack.size(), len = needle.size();

    	while(i < hay_len && j < len){
    		if(j == -1 || haystack[i] == needle[j]){
    			++i; ++j;
    		}else{
    			j = next[j];
    		}
    	}

    	if(j == len) return i - j;
    	return -1;
    }

    void getNext(string pattern, int next[]){ // get the next table
    	next[0] = -1;
    	int i = 0, j = -1;
    	while(i < pattern.size()) {
    		if(j == -1 || pattern[i] == pattern[j]){
    			++i; ++j;
    			next[i] = j;
    		}else {
    			j = next[j];
    		}
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string haystack, needle;
	while(cin >> haystack >> needle){
		cout << s.strStr(haystack, needle) << endl;
	}
	return 0;
}