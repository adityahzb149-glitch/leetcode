class Solution {
public:
    int hammingDistance(int x, int y) {
        // string binary1 = "";
        // string binary2 = "";

    bitset<32> b1(x);

    bitset<32> b2(y);

    int count = 0;

    for(size_t i = 0;i<b1.size();i++){
        if(b1[i]!=b2[i]){
            count++;
        } 
    }

    return count;
    }
};