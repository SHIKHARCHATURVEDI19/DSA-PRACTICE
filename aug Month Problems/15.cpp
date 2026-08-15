#include <string>

using namespace std;

class Solution {
public:
    int findKthDigit(long long k) {
    
        if (k <= 9) return k;
        k -= 9;

        long long len = 2;          
        long long nblocks = 9;       
        long long sblock = 1;      

        while (true) {
            long long ditier = nblocks * 10 * len;
            if (k <= ditier) break;
            
            k -= ditier;
            sblock += nblocks;
            nblocks *= 10;
            len++;
        }


        long long blockset = (k - 1) / (10 * len);
        long long block = sblock + blockset;
        k -= block * (10 * len); 

    
        long long intindex = (k - 1) / len; 
        long long dindex = (k - 1) % len;

        long long target;
        if (block % 2 == 0) {
            
            target = 10 * block + intindex;
        } else {
        
            target = 10 * block + (9 - intindex);
        }

        
        return to_string(target)[dindex] - '0';
    }
};