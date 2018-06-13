#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthofLongestSubstring(string s){
        if(s.size() == 0) return 0;
        int low = 0, high = low + 1;
        unordered_map<int, int> hash;
        hash[s[low]] = 0;
        int max_len = high - low;
        while(high < s.size()){
            if(hash.find(s[high]) == hash.end()){
                hash[s[high]] = high;
                high++;
            }else{
                hash.erase(s[low]);
                low++;
            }
            max_len = max(max_len, high - low);
        }
        return max_len;
    }
};

int main(){
    string str = "bbbbb";
    Solution s;
    int len = s.lengthofLongestSubstring(str);
    cout << "The final max len : " << len << endl;
    return 0;
}
