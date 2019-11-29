class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector < pair < int , int > > st;
        vector < int > ret;
        int sz = (int)asteroids.size();
        if(sz == 0){
            return ret;
        }
        vector < bool > exploded(sz , false);
        for(int i = 0;i < sz ; i++){
            if(asteroids[i] > 0){
                st.push_back({asteroids[i] , i});
            }else{
                while((int)st.size() > 0){
                    pair < int , int > bk = st.back();
                    st.pop_back();
                    if(abs(asteroids[i]) > bk.first){
                        exploded[bk.second] = true;
                        continue;
                    }
                    if(abs(asteroids[i]) < bk.first){
                        exploded[i] = true;
                        st.push_back(bk);
                        break;
                    }
                    if(abs(asteroids[i]) == bk.first){
                        exploded[bk.second] = true;
                        exploded[i] = true;
                        break;
                    }
                }
            }
        }
        for(int i = 0;i < sz; i++){
            if(!exploded[i]){
                ret.push_back(asteroids[i]);
            }
        }
        return ret;
        
    }
};
