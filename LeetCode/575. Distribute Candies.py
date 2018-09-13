class Solution(object):
    def distributeCandies(self, candies):
        candies.sort()
        dis = 0
        sz = len(candies)
        i = 1
        if sz>1:
            dis+=1
        while i<sz:
            if candies[i]!=candies[i-1]:
                dis+=1
            i+=1
        return min(dis,sz>>1)     
        
