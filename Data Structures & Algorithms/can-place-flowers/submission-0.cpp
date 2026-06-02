class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int empty = flowerbed[0] == 0 ? 1: 0;

        for(auto i: flowerbed){
            if(i == 1){
                n -=(empty-1)/2;
                empty = 0;
            }
            else{
                empty++;
            }
        }
        n-= empty/2;
        return n<=0
        ;
    }
};