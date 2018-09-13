class Solution {
    public int distributeCandies(int[] candies) {
        int sz = candies.length;
        Arrays.sort(candies);   
        int dis = 0;
        if(sz > 0){
            dis++;
        }
        for(int i = 1 ; i<sz ; i++){
            if(candies[i]!=candies[i-1]){dis++;}
        }
        int ret = sz/2;
        if(dis<ret){ret=dis;}
        return ret;
    }
}
