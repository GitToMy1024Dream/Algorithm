class Solution {
public:
    int sqrt(int x) {
        int left = 1;
        int right = x >>1;
        int last_mid = 0;
        if(x < 2)
            return x;
        while(left <= right)
            {
            const int mid = (left&right) +((left^right)>>1);
            if(x/mid > mid)
                {
                left = mid +1;
                last_mid = mid;
            }
            else if(x /mid < mid)
                {
                right = mid - 1;
            }
            else 
                return mid;
        }
        return last_mid;
    }
};