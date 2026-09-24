// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
         
        int FBV = -1;
        // if(left = 0){
        //     return left;
        // }

        while(left <= right){
            int mid = left + (right - left)/2;

            bool res = isBadVersion(mid);

            if(res ){
                FBV = mid;
                right = mid - 1;
            }else {
                left = mid + 1;
            }
            
        }

        return FBV;
    }
};