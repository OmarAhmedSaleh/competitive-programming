class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n = (int)list1.size();
        int m = (int)list2.size();
        int mn = n+m;
        vector<string> ans; 
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(list1[i] == list2[j]){
                    if(i+j < mn){
                        mn = i + j;
                        ans.clear();
                    }
                    if((i+j) == mn){
                        ans.push_back(list1[i]);
                    }
                }
            }
        }
        return ans;
    }
};
