// https://leetcode.com/explore/learn/card/binary-search/125/template-i/950/
#define LL long long

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        
        int lo = 1, hi = x;
        
        while (lo <= hi) {
            LL mid = lo + (hi - lo)/2;
            LL sqr = mid * mid;
            LL next_sqr = (mid + 1)*(mid + 1);
            
            if (sqr == x) {
                return mid;
            }
            else if (sqr > x) {
                hi = mid - 1;
            }
            else {
                if (next_sqr > x)
                    return mid;
                lo = mid + 1;
            }
        }
        
        return hi;
    }
};

/*
4
8
2
100
112
400
144
62500
2147395599
*/
