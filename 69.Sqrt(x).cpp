/*
class Solution {
public:
    int mySqrt(int x) {
        long l = 0;
        long r = static_cast<long> (x) + 1;
        
        while(l < r) {
            long m = (l+r)/2;
            if(m*m > x) {
                r = m;
            }else {
                l = m+1;
            }
        }
        
        return l-1;
    }
};
*/

class Solution {
public:
    int mySqrt(int x) {
        long r = static_cast<long>(x);
        while (r*r > x) {
            r = (r + x/r) / 2;
        }
        
        return int(r);
    }
};