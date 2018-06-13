#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    	if(x == 1) return x;
        int res = sqrt(x, 0, x);
        return res * res <= x ? res : res - 1;
    }

    int sqrt(int x, int low, int high) {
    	if(low >= high) return low;
    	int mid = (high + low) >> 1;
    	if (mid == x / mid) return mid;
    	else if(mid > x / mid) return sqrt(x, low, mid - 1);
    	else return sqrt(x, mid + 1, high);
    }
};

class Sqrt
{
public:
	int mySqrt(int x){
		if(x == 0 || x == 1) return x;

		int low = 1, high = x;
		int ans = low;
		while(low <= high){
			int mid = (low + high) >> 1;
			if(mid <= x / mid){
				low = mid + 1;
				ans = mid;
			}else{
				high = mid - 1;
			}
		}
		return ans;
	}
};


int main(int argc, char const *argv[])
{
	Sqrt s;
	int x;
	while(cin >> x){
		cout<< s.mySqrt(x) << endl;
	}
	return 0;
}