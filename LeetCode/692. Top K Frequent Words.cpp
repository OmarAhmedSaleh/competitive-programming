class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector < string > ret;
        map < string , int > mp;
        for(int i = 0;i < (int)words.size() ; i++){
            mp[words[i]]++;
        }
        vector < pair < int , string > > sortedArray;
        for(int i = 0;i < (int)words.size() ; i++){
            if(mp[words[i]] == 0){
                continue;
            }
            sortedArray.push_back({mp[words[i]] , words[i]});
            mp[words[i]] = 0;
        }
        sort(sortedArray.begin() , sortedArray.end() , sortPair);
        for(int i = 0;i < k ; i++){
            ret.push_back(sortedArray[i].second);
        }
        return ret;
    }
   static bool sortPair(pair < int , string > a , pair < int , string > b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
