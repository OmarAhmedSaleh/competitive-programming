class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int sz = (int)candies.size();
        sort(candies.begin(),candies.end());
        int dis = sz>0;
        for(int i = 1 ;i<sz;i++){
            dis+=candies[i]!=candies[i-1];
        }
        return min(sz>>1,dis);
    }
};
