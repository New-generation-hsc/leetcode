#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
    string longestPalindromeSubstring(string s){
        int len = s.size();
        if(len < 2) return s;

        bool tables[1000][1000] = {false};
        for(int i = 0; i < s.size(); i++){
            tables[i][i] = true;
        }

        int begin = 0;

        for(int i = 0; i < len-1; i++){
            if(s[i] == s[i+1]){
                tables[i][i+1] = true;
                begin = i;
            }
        }

        int maxLen = 2;

        for(int i = 2; i < len; i++){
            for(int j = 0; j < i; j++){
                if(s[i] == s[j] && tables[j+1][i-1]){
                    tables[j][i] = true;
                    if(maxLen < i - j + 1){
                        maxLen = i - j + 1;
                        begin = j;
                    }
                }
            }
        }

        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                cout << tables[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return s.substr(begin, maxLen);
    }
};

int main(){
    Solution s;
    string str = "ababa";
    cout << s.longestPalindromeSubstring(str) << endl;
    return 0;
}
