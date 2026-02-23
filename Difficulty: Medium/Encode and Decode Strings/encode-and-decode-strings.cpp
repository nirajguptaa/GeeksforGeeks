class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string str="";
        for(int i=0;i<s.size();i++){
            str+=s[i];
            if(i+1<s.size())str+=',';
        }
        return str;
    }

    vector<string> decode(string& s) {
        
        // code here
        vector<string>ans;
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]==','){
                ans.push_back(str);
                str="";
            }else{
                str+=s[i];
            }
        }
        ans.push_back(str);
        return ans;
    }
};