
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {      
        int n = (int)people.size();
        vector<pair<int,int>> ret;
        vector<int> SL;
        while((int)ret.size()<n){
            int idx = -1;
            for(int i=0;i<n;i++){
                if(people[i].first==-1){continue;}
                int pos = (int)(upper_bound(SL.begin(),SL.end(),people[i].first-1)-SL.begin());
                int cnt = (int)SL.size() - pos;
                if(cnt == people[i].second && (idx == -1 || people[i].first<people[idx].first)){
                    idx = i;
                }
            } 
            ret.push_back(people[idx]);
            SL.push_back(people[idx].first);
            sort(SL.begin(),SL.end());
            people[idx].first = -1;
        }
        return ret;
    }
};
