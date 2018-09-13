class Solution{
    public:
    int sz = 0;
    map<char,int> occ;
    vector<char> all;
    vector<string> all_pal;
    
   vector<string> generatePalindromes(string s){
    sz = (int)s.size();
    occ.clear();
	for(int i = 0;i<sz;i++){
	    occ[s[i]]++;
	    if(occ[s[i]]==1){
	        all.push_back(s[i]);
	    }
	}
    vector<string> ans;
    string str = "";
    for(int i = 0 ;i<sz ; i++){
        str+="0";
    }
    
    solve(0,sz-1,str);
    
    if((int)all_pal.size()){
        sort(all_pal.begin(),all_pal.end());
        ans.push_back(all_pal[0]);
    }
    for(int i = 1; i<(int)all_pal.size();i++){
        if(all_pal[i]!=ans.back()){
            ans.push_back(all_pal[i]);
        }
    }
        return ans;
    }
    
    void solve(int st,int ed,string s){
        if(st>ed){
            //cout << s << endl;
            all_pal.push_back(s);
            return ;
        }
        string ss = s;
        int cnt = 0;
        for(int i = 0 ; i<(int)all.size(); i++){
            cnt = occ[all[i]];
            if(cnt>0 && (st==ed) ){
                occ[all[i]]--;
                ss[st] = all[i];
                solve(st+1,ed-1,ss);
                occ[all[i]]++;
            } 
            if(cnt>1 && (st<ed)){
                occ[all[i]]-=2;
                ss[st]=ss[ed] = all[i];
                solve(st+1,ed-1,ss);
                occ[all[i]]+=2;
            }
        }
    }
};
