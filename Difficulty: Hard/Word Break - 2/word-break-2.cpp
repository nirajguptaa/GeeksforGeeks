// User function Template for C++
class Solution {
  public:
    void f(int idx,string s,unordered_set<string>&st,string curr,vector<string>&ans){
        int n=s.size();
        if(idx==n){
            curr.pop_back();
            ans.push_back(curr);
            return ;
        }
        string temp="";
        for(int i=idx;i<n;i++){
            temp+=s[i];
            if(st.count(temp)){
                f(i+1,s,st,curr+temp+" ",ans);
            }
        }
    }
    vector<string> wordBreak(vector<string>& dict, string& s) {
        // code here
        unordered_set<string>st;
        for(string &s:dict){
            st.insert(s);
        }
        vector<string>ans;
        f(0,s,st,"",ans);
        return ans;
    }
};